#include "KKUtils.h"

#include <iostream>

namespace KKUtils {
    void Builder::add_buffer(const size_t size) { data.resize(data.size() + size); }

    const std::vector<u8>& Builder::get() const { return data; };

    void Builder::set(const std::vector<u8>& v) {
        data.clear();
        data.insert(data.end(), v.begin(), v.end());
    }

    Imager::Imager(bool screen, const u16 x, const u16 y, const u16 width, const u16 height) {
        // I have _no_ idea how this protocol works
        // This just replicates what qKontrol does
        numPixels = width * height;
        dataTemplate.push(0x8400_U16);

        screenPos = dataTemplate.get().size();
        dataTemplate.push(u8{screen});

        dataTemplate.push(0x60000000_U32);
        dataTemplate.push(0x00_U8);

        xPos = dataTemplate.get().size();
        dataTemplate.push(x);

        yPos = dataTemplate.get().size();
        dataTemplate.push(y);

        dataTemplate.push(width);
        dataTemplate.push(height);

        dataTemplate.push(0x0200_U16);
        dataTemplate.push(0x00000000_U32);
        dataTemplate.push(static_cast<u16>(width * height / 2));

        imgPos = dataTemplate.get().size();
        dataTemplate.add_buffer(width * height * 2);

        dataTemplate.push(0x02000000_U32);
        dataTemplate.push(0x03000000_U32);
        dataTemplate.push(0x40000000_U32);

        // dataTemplate.print();
    }

    void Imager::setVec(const std::vector<u8>& v) {
        dataTemplate.set(v);
    }

    void Imager::setX(const u16 x) { dataTemplate.insert(xPos, x); }
    void Imager::setY(const u16 y) { dataTemplate.insert(yPos, y); }
    void Imager::setS(const bool s) { dataTemplate.insert(screenPos, s); }

    void Imager::write_img(const std::vector<u8>& data) {
        if (data.size() != numPixels * 2) {
            printf("Wrong number of pixels! %#lx got, %#lx expected", data.size() / 2, numPixels);
            return;
        }

        std::vector<u8> v = dataTemplate.get();
        std::copy(data.begin(), data.end(), v.begin() + static_cast<long>(imgPos));
        dataTemplate.set(v);
    }

    void Imager::send(libusb_device_handle* keyboard) const {
        int transferred;
        libusb_bulk_transfer(keyboard, 3, const_cast<u8*>(dataTemplate.get().data()), dataTemplate.get().size(), &transferred, 0);
    }

    const std::vector<u8>& Imager::get() const { return dataTemplate.get(); }
} // namespace KKUtils
