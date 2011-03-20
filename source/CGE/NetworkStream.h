#ifndef NETWORKSTREAM_H
#define NETWORKSTREAM_H

#include <SDL_net.h>

namespace CGE
{
    class NetworkStream
    {
        public:
            NetworkStream(size_t inPacketSize = 1024);
            ~NetworkStream();

            inline size_t size() const { return mSize; }
            void openSocket(Uint16 inPort = 0);
            void connect(const char* inAddress, Uint16 inPort);
            void sendData(const void* inData, size_t inLength);
            bool receiveData(Uint8* inCapture);

        private:
            NetworkStream(const NetworkStream& inStream)
            {
                // no copying
            }

            NetworkStream& operator=(const NetworkStream& inStream)
            {
                // no copying
                return *this;
            }

            IPaddress mAddress;
            UDPsocket mSocket;
            size_t mSize;
            UDPpacket* mPacket;
    };
}

#endif
