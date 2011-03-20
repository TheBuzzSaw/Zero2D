#include "Download.h"
#include <curl/curl.h>

namespace CGE
{
    size_t Download::writeData(void* inData, size_t inSize, size_t inCount,
        void* inObject)
    {
        Download* d = static_cast<Download*>(inObject);
        size_t outTotal = inSize * inCount;
        const char* c = static_cast<const char*>(inData);
        d->mStream->write(c, outTotal);
        return outTotal;
    }

    int Download::progressUpdate(void* inObject, double inTotalToDownload,
        double inNowDownloaded, double inTotalToUpload, double inNowUploaded)
    {
        Download* d = static_cast<Download*>(inObject);
        d->mProgress = inNowDownloaded / inTotalToDownload;
        return d->stopRequested();
    }

    Download::Download() : mSource(NULL), mDestination(NULL), mProgress(0.0)
    {
    }

    Download::~Download()
    {
    }

    void Download::configure(const char* inSource, const char* inDestination)
    {
        mSource = inSource;
        mDestination = inDestination;
    }

    void Download::run()
    {
        mProgress = 0.0;

        if (!mSource || !*mSource || !mDestination || !*mDestination)
            return;

        std::ofstream fout(mDestination, std::ofstream::binary);
        if (!fout) return;

        mStream = &fout;

        CURL* c = curl_easy_init();
        curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(c, CURLOPT_WRITEDATA, this);
        curl_easy_setopt(c, CURLOPT_NOPROGRESS, 0);
        curl_easy_setopt(c, CURLOPT_PROGRESSFUNCTION, progressUpdate);
        curl_easy_setopt(c, CURLOPT_PROGRESSDATA, this);
        curl_easy_setopt(c, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(c, CURLOPT_URL, mSource);

        CURLcode result = curl_easy_perform(c); // perform download

        switch (result)
        {
            case 0:
                mProgress = 1.0;
                break;

            case CURLE_ABORTED_BY_CALLBACK:
                // stopped by a CGE::Thread stop request
            default: {}
        }

        curl_easy_cleanup(c);

        fout.close();
    }
}

