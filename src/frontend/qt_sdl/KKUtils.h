#pragma once

#include <vector>
#include <type_traits>

#include <libusb.h>

#include "types.h"

namespace KKUtils {
    using namespace melonDS;

    class Builder {
    public:
        template <class T>
        void push(T val)
        {
            // Needs to be split to 8-bit chunks
            for (size_t i = 1; i <= sizeof(T); i++) {
                size_t offset = sizeof(T) * 8 - i * 8;
                unsigned char extracted = (val >> offset) & 0xff;

                data.push_back(extracted);
            }
        }

        void add_buffer(size_t size);

        [[nodiscard]] const std::vector<u8>& get() const;

        void set(const std::vector<u8>& v);

        template <class T>
        void insert(const size_t pos, T val)
        {
            // Needs to be split to 8-bit chunks
            for (size_t i = 1; i <= sizeof(val); i++) {
                size_t offset = sizeof(val) * 8 - i * 8;
                const unsigned char extracted = (val >> offset) & 0xff;

                data[pos + i - 1] = extracted;
            }
        };

    private:
        std::vector<u8> data;
    };

    class Imager {
    public:
        Imager(std::initializer_list<Imager> l) : Imager(0, 0, 0, 0, 0) {
            std::vector<u8> v;
            for (auto& i : l) {
                v.insert(v.end(), i.get().begin(), i.get().end());
            }
            dataTemplate.set(v);
        }
        Imager(bool screen, u16 x, u16 y, u16 width, u16 height);

        void setVec(const std::vector<u8>& v);

        void setX(u16 x);
        void setY(u16 y);
        void setS(bool s);

        void write_img(const std::vector<u8>& data);

        void send(libusb_device_handle* keyboard) const;

        [[nodiscard]] const std::vector<u8>& get() const;

    private:
        size_t xPos, yPos;
        size_t screenPos;
        size_t imgPos;
        size_t numPixels;
        Builder dataTemplate;
    };
} // namespace KKUtils
