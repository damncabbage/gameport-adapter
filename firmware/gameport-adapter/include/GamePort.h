// This file is part of Necroware's GamePort adapter firmware.
// Copyright (C) 2021 Necroware
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#pragma once

// Simple GamePort pins to Arduino pins mapper.
// GamePort pins <1>, <8>, <9> are already connected to "VCC".
// GamePort pins <4>, <5> are already connected to GND.
template <int I>
struct GamePort {
  enum { pin = -1 };
};

// Pin mapping; format: 'Gameport Pin [Board Pin]'
//
// 1[V]   2[10]   3[A0]     4[G]      5[G]     6[A3]      7[15]      8[V]
//    9[V]    10[16]   11[A1]   12[A8]   13[A2]     14[14]     15[A9]

// Analog: Button #1
// Digital (e.g. SW3D): Clock
template <>
struct GamePort<2> {
  enum { pin = 10 };
};

// Analog: Joystick1 X-Axis 
// Digital (e.g. SW3D): Trigger
template <>
struct GamePort<3> {
  enum { pin = A0 };
};

// Analog: Joystick1 Y-Axis 
template <>
struct GamePort<6> {
  enum { pin = A3 };
};

// Analog: Button #2
// Digital (e.g. SW3D): Data 0
template <>
struct GamePort<7> {
  enum { pin = 15 };
};

// Analog: Button #3
// Digital (e.g. SW3D): Data 1
template <>
struct GamePort<10> {
  enum { pin = 16 };
};

// Analog: Joystick2 X-Axis 
template <>
struct GamePort<11> {
  enum { pin = A1 };
};

// Analog: Midi OUT
template <>
struct GamePort<12> {
  enum { pin = A8 };
};

// Analog: Joystick2 Y-Axis 
template <>
struct GamePort<13> {
  enum { pin = A2 };
};

// Analog: Button #4
// Digital (e.g. SW3D): Data 2
template <>
struct GamePort<14> {
  enum { pin = 14 };
};

// Analog: Midi IN
template <>
struct GamePort<15> {
  enum { pin = A9 };
};
