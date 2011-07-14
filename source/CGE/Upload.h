#ifndef UPLOAD_H
#define UPLOAD_H

#include "Thread.h"

namespace CGE
{
    class Upload : public Thread
    {
        public:
            Upload();
            virtual ~Upload();

            void configure(const char* inSource, const char* inDestination);
            inline double progress() const { return mProgress; }

            virtual void run();

        private:
            static int progressUpdate(void* inObject, double inTotalToDownload,
                double inNowDownloaded, double inTotalToUpload,
                double inNowUploaded);

            const char* mSource;
            const char* mDestination;
            volatile double mProgress;
    };
}

#endif
