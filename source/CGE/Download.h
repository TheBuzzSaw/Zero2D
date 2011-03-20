#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "Thread.h"
#include <fstream>

namespace CGE
{
    class Download : public Thread
    {
        public:
            Download();
            ~Download();

            void configure(const char* inSource, const char* inDestination);
            inline double progress() const { return mProgress; }

            virtual void run();

        private:
            static int progressUpdate(void* inObject, double inTotalToDownload,
                double inNowDownloaded, double inTotalToUpload,
                double inNowUploaded);

            static size_t writeData(void* inData, size_t inSize, size_t inCount,
                void* inObject);

            const char* mSource;
            const char* mDestination;
            std::ofstream* mStream;
            volatile double mProgress;
    };
}

#endif
