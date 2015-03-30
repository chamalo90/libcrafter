/*
Copyright (c) 2012, Esteban Pellegrino
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ESTEBAN PELLEGRINO BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef TCPOPTIONEXTENDEDDATAOFFSET_H_
#define TCPOPTIONEXTENDEDDATAOFFSET_H_

#include "TCPOptionLayer.h"


#ifndef TCPOPT_EDO
#define TCPOPT_EDO  31
#endif

namespace Crafter {

    class TCPOptionExtendedDataOffset: public TCPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCPOptionExtendedDataOffset::TCPOptionExtendedDataOffsetConstFunc;
        };

        static Layer* TCPOptionExtendedDataOffsetConstFunc() {
            return new TCPOptionExtendedDataOffset;
        };

        void Craft();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldKind = 0;
        static const byte FieldLength = 1;
        static const byte FieldHeader_length = 2;

    public:

        static const word PROTO = 0x0ED0;

        TCPOptionExtendedDataOffset();

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetHeader_length(const word& value) {
            SetFieldValue(FieldHeader_length,value);
        };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        word  GetHeader_length() const {
            return GetFieldValue<word>(FieldHeader_length);
        };

        ~TCPOptionExtendedDataOffset() { /* Destructor */ };

        static TCPOptionLayer* Build(int subopt);

    };

     class TCPOptionExtendedDataOffsetRequest: public TCPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCPOptionExtendedDataOffsetRequest::TCPOptionExtendedDataOffsetRequestConstFunc;
        };

        static Layer* TCPOptionExtendedDataOffsetRequestConstFunc() {
            return new TCPOptionExtendedDataOffsetRequest;
        };

        void Craft();

        static const byte FieldKind = 0;
        static const byte FieldLength = 1;

    public:

        static const word PROTO = 0x0ED0;

        TCPOptionExtendedDataOffsetRequest();

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        ~TCPOptionExtendedDataOffsetRequest() { /* Destructor */ };

    };

}

#endif /* TCPOPTIONEXTENDEDDATAOFFSET_H_ */
