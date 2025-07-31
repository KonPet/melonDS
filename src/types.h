/*
    Copyright 2016-2025 melonDS team

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <array>

namespace melonDS
{
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef int64_t     s64;

inline u8 operator""_U8(unsigned long long a) { return static_cast<u8>(a); }
inline u16 operator""_U16(unsigned long long a) { return static_cast<u16>(a); }
inline u32 operator""_U32(unsigned long long a) { return static_cast<u32>(a); }
inline u64 operator""_U64(unsigned long long a) { return static_cast<u64>(a); }

inline s8 operator""_S8(unsigned long long a) { return static_cast<s8>(a); }
inline s16 operator""_S16(unsigned long long a) { return static_cast<s16>(a); }
inline s32 operator""_S32(unsigned long long a) { return static_cast<s32>(a); }
inline s64 operator""_S64(unsigned long long a) { return static_cast<s64>(a); }

template<class T, std::size_t A, std::size_t B>
using array2d = std::array<std::array<T, B>, A>;
}
#endif // TYPES_H
