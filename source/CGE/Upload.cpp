#include "Upload.h"

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

namespace CGE
{
    int Upload::progressUpdate(void* inObject, double inTotalToDownload,
        double inNowDownloaded, double inTotalToUpload, double inNowUploaded)
    {
        Upload* u = static_cast<Upload*>(inObject);
        u->mProgress = inNowDownloaded / inTotalToDownload;
        return u->stopRequested();
    }

    Upload::Upload()
    {
    }

    Upload::~Upload()
    {
    }

    void Upload::configure(const char* inSource, const char* inDestination)
    {
        mSource = inSource;
        mDestination = inDestination;
    }

    void Upload::run()
    {
        static const char* buffer = "Expect:";
        curl_httppost* formPost = NULL;
        curl_httppost* lastPointer = NULL;
        curl_slist* headerList = NULL;

        curl_formadd(&formPost, &lastPointer, CURLFORM_COPYNAME, "sendfile",
            CURLFORM_FILE, mSource, CURLFORM_END);

        CURL* c = curl_easy_init();

        headerList = curl_slist_append(headerList, buffer);

        if (c)
        {
            //curl_easy_setopt(c, CURLOPT_NOPROGRESS, 0);
            //curl_easy_setopt(c, CURLOPT_PROGRESSFUNCTION, progressUpdate);
            //curl_easy_setopt(c, CURLOPT_PROGRESSDATA, this);
            curl_easy_setopt(c, CURLOPT_URL, mDestination);
            curl_easy_setopt(c, CURLOPT_HTTPPOST, formPost);

            CURLcode result = curl_easy_perform(c);

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
            curl_formfree(formPost);
            curl_slist_free_all(headerList);
        }
    }
}
