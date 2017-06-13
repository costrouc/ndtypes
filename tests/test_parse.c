/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, plures
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <stdio.h>
#include "test.h"


const char *parse_tests[] = {
  "2395344366 * Any",
  "N * Any",
  "N * M * Any",
  "10 * 2395344366 * Any",
  "10 * 10 * 2395344366 * Any",
  "L * Any",
  "10 * L * Any",
  "10 * 10 * L * Any",
  "var * Any",
  "10 * var * Any",
  "10 * 10 * var * Any",
  "... * Any",
  "10 * ... * Any",
  "10 * 10 * ... * Any",
  "10 * Any",
  "Any",
  "10 * ScalarKind",
  "ScalarKind",
  "10 * void",
  "void",
  "10 * bool",
  "bool",
  "10 * SignedKind",
  "SignedKind",
  "10 * int8",
  "int8",
  "10 * int16",
  "int16",
  "10 * int32",
  "int32",
  "10 * int64",
  "int64",
  "10 * UnsignedKind",
  "UnsignedKind",
  "10 * uint8",
  "uint8",
  "10 * uint16",
  "uint16",
  "10 * uint32",
  "uint32",
  "10 * uint64",
  "uint64",
  "10 * RealKind",
  "RealKind",
  "10 * float32",
  "float32",
  "10 * float64",
  "float64",
  "10 * ComplexKind",
  "ComplexKind",
  "10 * complex64",
  "complex64",
  "10 * complex128",
  "complex128",
  "10 * int",
  "int",
  "10 * real",
  "real",
  "10 * complex",
  "complex",
  "10 * intptr",
  "intptr",
  "10 * uintptr",
  "uintptr",
  "10 * char",
  "char",
  "10 * char('A')",
  "char('A')",
  "10 * char('ascii')",
  "char('ascii')",
  "10 * char('us-ascii')",
  "char('us-ascii')",
  "10 * char('U8')",
  "char('U8')",
  "10 * char('utf8')",
  "char('utf8')",
  "10 * char('utf-8')",
  "char('utf-8')",
  "10 * char('U16')",
  "char('U16')",
  "10 * char('utf16')",
  "char('utf16')",
  "10 * char('utf-16')",
  "char('utf-16')",
  "10 * char('U32')",
  "char('U32')",
  "10 * char('utf32')",
  "char('utf32')",
  "10 * char('utf-32')",
  "char('utf-32')",
  "10 * char('ucs2')",
  "char('ucs2')",
  "10 * char('ucs-2')",
  "char('ucs-2')",
  "10 * char('ucs_2')",
  "char('ucs_2')",
  "10 * string",
  "string",
  "10 * FixedStringKind",
  "FixedStringKind",
  "10 * fixed_string(3641573028)",
  "fixed_string(3641573028)",
  "10 * fixed_string(4053683685, 'A')",
  "fixed_string(4053683685, 'A')",
  "10 * fixed_string(729742655, 'ascii')",
  "fixed_string(729742655, 'ascii')",
  "10 * fixed_string(3675114521, 'us-ascii')",
  "fixed_string(3675114521, 'us-ascii')",
  "10 * fixed_string(1506029184, 'U8')",
  "fixed_string(1506029184, 'U8')",
  "10 * fixed_string(3952068488, 'utf8')",
  "fixed_string(3952068488, 'utf8')",
  "10 * fixed_string(966590426, 'utf-8')",
  "fixed_string(966590426, 'utf-8')",
  "10 * fixed_string(1439340594, 'U16')",
  "fixed_string(1439340594, 'U16')",
  "10 * fixed_string(2949183030, 'utf16')",
  "fixed_string(2949183030, 'utf16')",
  "10 * fixed_string(2591745097, 'utf-16')",
  "fixed_string(2591745097, 'utf-16')",
  "10 * fixed_string(3116157301, 'U32')",
  "fixed_string(3116157301, 'U32')",
  "10 * fixed_string(375133997, 'utf32')",
  "fixed_string(375133997, 'utf32')",
  "10 * fixed_string(3253997171, 'utf-32')",
  "fixed_string(3253997171, 'utf-32')",
  "10 * fixed_string(969064578, 'ucs2')",
  "fixed_string(969064578, 'ucs2')",
  "10 * fixed_string(2403487820, 'ucs-2')",
  "fixed_string(2403487820, 'ucs-2')",
  "10 * fixed_string(2347175950, 'ucs_2')",
  "fixed_string(2347175950, 'ucs_2')",
  "10 * bytes(align=2)",
  "bytes(align=4)",
  "10 * FixedBytesKind",
  "FixedBytesKind",
  "10 * fixed_bytes(size=1904128733, align=4)",
  "fixed_bytes(size=1904128733, align=4)",
  "10 * categorical(63 : int8)",
  "categorical(63 : int8)",
  "10 * categorical(10 : int64, 63 : int8)",
  "categorical(10 : int64, 63 : int8)",
  "10 * categorical(10 : int64, 20 : int64, 63 : int8)",
  "categorical(10 : int64, 20 : int64, 63 : int8)",
  "10 * categorical(18514 : int16)",
  "categorical(18514 : int16)",
  "10 * categorical(10 : int64, 18514 : int16)",
  "categorical(10 : int64, 18514 : int16)",
  "10 * categorical(10 : int64, 20 : int64, 18514 : int16)",
  "categorical(10 : int64, 10 : float64, 18514 : int16)",
  "10 * categorical(-176354404 : int32)",
  "categorical(-176354404 : int32)",
  "10 * categorical(10 : int64, -176354404 : int32)",
  "categorical(10 : int64, -176354404 : int32)",
  "10 * categorical(10 : int64, 10 : uint16, -176354404 : int32)",
  "categorical(10 : int64, 20 : int64, -176354404 : int32)",
  "10 * categorical(500601201 : int64)",
  "categorical(500601201 : int64)",
  "10 * categorical(10 : int64, 500601201 : int64)",
  "categorical(10 : int64, 500601201 : int64)",
  "10 * categorical(10 : int64, 10 : float32, 500601201 : int64)",
  "categorical(10 : int64, 20 : int64, 500601201 : int64)",
  "10 * categorical(135 : uint8)",
  "categorical(135 : uint8)",
  "10 * categorical(10 : int64, 135 : uint8)",
  "categorical(10 : int64, 135 : uint8)",
  "10 * categorical(10 : int64, 20 : int64, 135 : uint8)",
  "categorical(10 : int64, 20 : int64, 135 : uint8)",
  "10 * categorical(22234 : uint16)",
  "categorical(22234 : uint16)",
  "10 * categorical(10 : int64, 22234 : uint16)",
  "categorical(10 : int64, 22234 : uint16)",
  "10 * categorical(10 : int64, 20 : int64, 22234 : uint16)",
  "categorical(10 : int64, 20 : int64, 22234 : uint16)",
  "10 * categorical(3761672407 : uint32)",
  "categorical(3761672407 : uint32)",
  "10 * categorical(10 : int64, 3761672407 : uint32)",
  "categorical(10 : int64, 3761672407 : uint32)",
  "10 * categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
  "categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
  "10 * categorical(2339269771 : uint64)",
  "categorical(2339269771 : uint64)",
  "10 * categorical(10 : int64, 2339269771 : uint64)",
  "categorical(10 : int64, 2339269771 : uint64)",
  "10 * categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
  "categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
  "10 * categorical(147573419.42583135 : float32)",
  "categorical(147573419.42583135 : float32)",
  "10 * categorical(10 : int64, 147573419.42583135 : float32)",
  "categorical(10 : int64, 147573419.42583135 : float32)",
  "10 * categorical(10 : int64, 20 : int64, 147573419.42583135 : float32)",
  "categorical(10 : int64, 20 : int64, 147573419.42583135 : float32)",
  "10 * categorical(541537316.9378864 : float64)",
  "categorical(541537316.9378864 : float64)",
  "10 * categorical(10 : int64, 541537316.9378864 : float64)",
  "categorical(10 : int64, 541537316.9378864 : float64)",
  "10 * categorical(10 : int64, 20 : int64, 541537316.9378864 : float64)",
  "categorical(10 : int64, 20 : int64, 541537316.9378864 : float64)",
  "10 * categorical('jRAMoBPQ' : string)",
  "categorical('jRAMoBPQ' : string)",
  "10 * categorical(10 : int64, 'jRAMoBPQ' : string)",
  "categorical(10 : int64, 'jRAMoBPQ' : string)",
  "10 * categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
  "categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
  "10 * categorical(127 : int8)",
  "categorical(127 : int8)",
  "10 * categorical(10 : int64, 127 : int8)",
  "categorical(10 : int64, 127 : int8)",
  "10 * categorical(10 : int64, 20 : int64, 127 : int8)",
  "categorical(10 : int64, 20 : int64, 127 : int8)",
  "10 * categorical(-128 : int8)",
  "categorical(-128 : int8)",
  "10 * categorical(10 : int64, -128 : int8)",
  "categorical(10 : int64, -128 : int8)",
  "10 * categorical(10 : int64, 20 : int64, -128 : int8)",
  "categorical(10 : int64, 20 : int64, -128 : int8)",
  "10 * categorical(32767 : int16)",
  "categorical(32767 : int16)",
  "10 * categorical(10 : int64, 32767 : int16)",
  "categorical(10 : int64, 32767 : int16)",
  "10 * categorical(10 : int64, 20 : int64, 32767 : int16)",
  "categorical(10 : int64, 20 : int64, 32767 : int16)",
  "10 * categorical(-32768 : int16)",
  "categorical(-32768 : int16)",
  "10 * categorical(10 : int64, -32768 : int16)",
  "categorical(10 : int64, -32768 : int16)",
  "10 * categorical(10 : int64, 20 : int64, -32768 : int16)",
  "categorical(10 : int64, 20 : int64, -32768 : int16)",
  "10 * categorical(2147483647 : int32)",
  "categorical(2147483647 : int32)",
  "10 * categorical(10 : int64, 2147483647 : int32)",
  "categorical(10 : int64, 2147483647 : int32)",
  "10 * categorical(10 : int64, 20 : int64, 2147483647 : int32)",
  "categorical(10 : int64, 20 : int64, 2147483647 : int32)",
  "10 * categorical(-2147483648 : int32)",
  "categorical(-2147483648 : int32)",
  "10 * categorical(10 : int64, -2147483648 : int32)",
  "categorical(10 : int64, -2147483648 : int32)",
  "10 * categorical(10 : int64, 20 : int64, -2147483648 : int32)",
  "categorical(10 : int64, 20 : int64, -2147483648 : int32)",
  "10 * categorical(9223372036854775807 : int64)",
  "categorical(9223372036854775807 : int64)",
  "10 * categorical(10 : int64, 9223372036854775807 : int64)",
  "categorical(10 : int64, 9223372036854775807 : int64)",
  "10 * categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
  "categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
  "10 * categorical(-9223372036854775808 : int64)",
  "categorical(-9223372036854775808 : int64)",
  "10 * categorical(10 : int64, -9223372036854775808 : int64)",
  "categorical(10 : int64, -9223372036854775808 : int64)",
  "10 * categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
  "categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
  "10 * categorical(255 : uint8)",
  "categorical(255 : uint8)",
  "10 * categorical(10 : int64, 255 : uint8)",
  "categorical(10 : int64, 255 : uint8)",
  "10 * categorical(10 : int64, 20 : int64, 255 : uint8)",
  "categorical(10 : int64, 20 : int64, 255 : uint8)",
  "10 * categorical(65535 : uint16)",
  "categorical(65535 : uint16)",
  "10 * categorical(10 : int64, 65535 : uint16)",
  "categorical(10 : int64, 65535 : uint16)",
  "10 * categorical(10 : int64, 20 : int64, 65535 : uint16)",
  "categorical(10 : int64, 20 : int64, 65535 : uint16)",
  "10 * categorical(4294967295 : uint32)",
  "categorical(4294967295 : uint32)",
  "10 * categorical(10 : int64, 4294967295 : uint32)",
  "categorical(10 : int64, 4294967295 : uint32)",
  "10 * categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
  "categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
  "10 * categorical(18446744073709551615 : uint64)",
  "categorical(18446744073709551615 : uint64)",
  "10 * categorical(10 : int64, 18446744073709551615 : uint64)",
  "categorical(10 : int64, 18446744073709551615 : uint64)",
  "10 * categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
  "categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
  "10 * categorical(1.17550e-38 : float32)",
  "categorical(1.17550e-38 : float32)",
  "10 * categorical(10 : int64, 1.17550e-38 : float32)",
  "categorical(10 : int64, 1.17550e-38 : float32)",
  "10 * categorical(10 : int64, 20 : int64, 1.17550e-38 : float32)",
  "categorical(10 : int64, 20 : int64, 1.17550e-38 : float32)",
  "10 * categorical(2.22508e-308 : float64)",
  "categorical(2.22508e-308 : float64)",
  "10 * categorical(10 : int64, 2.22508e-308 : float64)",
  "categorical(10 : int64, 2.22508e-308 : float64)",
  "10 * categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
  "categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
  "10 * categorical(3.40282e+38 : float32)",
  "categorical(3.40282e+38 : float32)",
  "10 * categorical(10 : int64, 3.40282e+38 : float32)",
  "categorical(10 : int64, 3.40282e+38 : float32)",
  "10 * categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
  "categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
  "10 * categorical(1.79769e+308 : float64)",
  "categorical(1.79769e+308 : float64)",
  "10 * categorical(10 : int64, 1.79769e+308 : float64)",
  "categorical(10 : int64, 1.79769e+308 : float64)",
  "10 * categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
  "categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
  "10 * categorical(\"\" : string)",
  "categorical(\"\" : string)",
  "10 * categorical(10 : int64, \"\" : string)",
  "categorical(10 : int64, \"\" : string)",
  "10 * categorical(10 : int64, 20 : int64, \"\" : string)",
  "categorical(10 : int64, 20 : int64, \"\" : string)",
  "10 * categorical('' : string)",
  "categorical('' : string)",
  "10 * categorical(10 : int64, '' : string)",
  "categorical(10 : int64, '' : string)",
  "10 * categorical(10 : int64, 20 : int64, '' : string)",
  "categorical(10 : int64, 20 : int64, '' : string)",
  "10 * categorical(\"xyz\" : string)",
  "categorical(\"xyz\" : string)",
  "10 * categorical(10 : int64, \"xyz\" : string)",
  "categorical(10 : int64, \"xyz\" : string)",
  "10 * categorical(10 : int64, 20 : int64, \"xyz\" : string)",
  "categorical(10 : int64, 20 : int64, \"xyz\" : string)",
  "10 * categorical('xyz' : string)",
  "categorical('xyz' : string)",
  "10 * categorical(10 : int64, 'xyz' : string)",
  "categorical(10 : int64, 'xyz' : string)",
  "10 * categorical(10 : int64, 20 : int64, 'xyz' : string)",
  "categorical(10 : int64, 20 : int64, 'xyz' : string)",
  "10 * pointer(Any)",
  "pointer(Any)",
  "10 * (...)",
  "(...)",
  "10 * (Any)",
  "(Any)",
  "10 * (int64, Any)",
  "(int64, Any)",
  "10 * (int64, int64, Any)",
  "(int64, int64, Any)",
  "10 * (Any)",
  "(Any)",
  "10 * (Any, )",
  "(Any, )",
  "10 * (Any, ...)",
  "(Any, ...)",
  "10 * {...}",
  "{...}",
  "10 * {a: Any}",
  "{a: Any}",
  "10 * {x: int64, a: Any}",
  "{x: int64, a: Any}",
  "10 * {x: int64, x: int64, a: Any}",
  "{x: int64, x: int64, a: Any}",
  "10 * {a : int64}",
  "{a : int64}",
  "10 * {a : int64, }",
  "{a : int64, }",
  "10 * {a : int64, ...}",
  "{a : int64, ...}",
  "10 * (...)-> Any",
  "(...)-> Any",
  "10 * ()->(...)",
  "()->(...)",
  "10 * (Any)-> Any",
  "(Any)-> Any",
  "10 * ()->(Any)",
  "()->(Any)",
  "10 * (int64, Any)-> Any",
  "(int64, Any)-> Any",
  "10 * ()->(int64, Any)",
  "()->(int64, Any)",
  "10 * (int64, int64, Any)-> Any",
  "(int64, int64, Any)-> Any",
  "10 * ()->(int64, int64, Any)",
  "()->(int64, int64, Any)",
  "10 * (Any)-> Any",
  "(Any)-> Any",
  "10 * ()->(Any)",
  "()->(Any)",
  "10 * (Any, )-> Any",
  "(Any, )-> Any",
  "10 * ()->(Any, )",
  "()->(Any, )",
  "10 * (Any, ...)-> Any",
  "(Any, ...)-> Any",
  "10 * ()->(Any, ...)",
  "()->(Any, ...)",
  "10 * (a: Any, ...) -> Any",
  "(a: Any) -> int64",
  "10 * (a: Any, ...) -> Any",
  "(a: Any, ...) -> Any",
  "10 * (x: int64, a: Any, ...) -> Any",
  "(x: int64, a: Any, ...) -> Any",
  "10 * (x: int64, x: int64, a: Any, ...) -> Any",
  "(x: int64, x: int64, a: Any, ...) -> Any",
  "10 * (Any) -> Any",
  "(Any) -> Any",
  "10 * (Any, ) -> Any",
  "(Any, ) -> Any",
  "10 * (Any, ...) -> Any",
  "(Any, ...) -> Any",
  "10 * (Any, a : Any) -> Any",
  "(Any, a : Any) -> Any",
  "10 * (Any, ..., a : Any) -> Any",
  "(Any, ..., a : Any) -> Any",
  "10 * (int64, Any, a : Any) -> Any",
  "(int64, Any, a : Any) -> Any",
  "10 * (int64, Any, ..., a : Any) -> Any",
  "(int64, Any, ..., a : Any) -> Any",
  "10 * (int64, int64, Any, a : Any) -> Any",
  "(int64, int64, Any, a : Any) -> Any",
  "10 * (int64, int64, Any, ..., a : Any) -> Any",
  "(int64, int64, Any, ..., a : Any) -> Any",
  "10 * (Any, a: Any) -> Any",
  "(Any, a: Any) -> Any",
  "10 * (Any, x: int64, a: Any) -> Any",
  "(Any, x: int64, a: Any) -> Any",
  "10 * (Any, x: int64, x: int64, a: Any) -> Any",
  "(Any, x: int64, x: int64, a: Any) -> Any",
  "10 * (Any, a : Any) -> Any",
  "(Any, a : Any) -> Any",
  "10 * (Any, ..., a : Any) -> Any",
  "(Any, ..., a : Any) -> Any",
  "10 * (Any, a : Any, ) -> Any",
  "(Any, a : Any, ) -> Any",
  "10 * (Any, ..., a : Any, ) -> Any",
  "(Any, ..., a : Any, ) -> Any",
  "10 * (Any, a : Any, ...) -> Any",
  "(Any, a : Any, ...) -> Any",
  "10 * (Any, ..., a : Any, ...) -> Any",
  "(Any, ..., a : Any, ...) -> Any",
  "10 * Up",
  "Up",
  "10 * X(Any)",
  "X(Any)",

  /* BEGIN RANDOM */
  "fixed_bytes(size=1342281638, align=16)",
  "ZmQxcy * var * 1098824011 * var * var * (...)",
  "categorical(\"a\" : string, 1619552300 : uint64, 49062 : uint16, 18772 : int16, -84 : int8, 'l' : string)",
  "categorical(408786241.474 : float64, 2840608325 : uint32, 44038 : uint16, 1763886348 : uint32, 'jOt' : string, 24 : uint8)",
  "categorical(-2049848438 : int32, 94 : uint8, 3599739756 : uint64, 3577056037 : uint32, 318483846.634 : float32)",
  "categorical(2753441703 : uint32, -67247918.4053 : float32)",
  "1293035889 * SQc2jI * 508611408 * var * ... * var * FYqqwF * VKte * string",
  "1286044356 * LbR6JPFI * 2096958782 * uint8",
  "categorical(-507014936.36 : float64, -25910 : int16, 'xM3Mys0XqH' : string, 4265882500 : uint64)",
  "var * 279953679 * NaZyx * ZQ * 221035040 * var * 1446706288 * FixedBytesKind",
  "SJBOs2xZm * var * ... * 4142176455 * BeL * 584505763 * Nf",
  "S * 3750021327 * 66749723 * var * var * var * 3816827158 * IhlydZ515 * 1507982035 * fixed_bytes(size=2816010943, align=16)",
  "3663546803 * 1650974226 * fixed_bytes(size=912328236, align=2)",
  "var * 2070943041 * 1423633425 * var * WOC6j * 3185909577 * real",
  "BfM2hS6zey * var * 163901665 * var * 747688899 * FbU2mb * var * ZcTmBXnKPi",
  "3334650506 * var * var * ... * void",
  "categorical('omhwkoWVWw' : string, 43 : uint8, 946986991 : int64)",
  "2857261760 * var * 888172155 * float32",
  "RZxERR * var * var * 2828578146 * var * 2925191533 * uint16",
  "2995650016 * var * N_IeNyWYjQ * ... * int16",
  "var * var * var * 3340205417 * 2074830512 * ScalarKind",
  "fixed_bytes(size=280180385, align=2)",
  "fixed_string(1901614748, 'utf-32')",
  "A8w8pNJ * 3945513946 * 3057917060 * var * IFB * 1919373335 * M7",
  "3546970538 * var * 542837605 * J0fcbFoNy3 * 1766819960 * bytes(align=2)",
  "3608776903 * MYlGTj * 1980216455 * Hce1_dqKx * var * Jfl * ... * E",
  "2948091211 * ... * categorical(-1869840431 : int64, 2052908559 : uint32)",
  "NXQv2GpkmX * ... * var * var * ULy8(char)",
  "fixed_bytes(size=1882259764, align=16)",
  "categorical(-136747211.015 : float32, -58 : int8, -83 : int8)",
  "3739637665 * 1476113530 * 1701021063 * IKd * 450514382 * WXn",
  "pointer(AilcKv4su1(FixedBytesKind))",
  "R79_AhZau0 * 950069447 * 2112203142 * 3298306739 * var * ... * complex128",
  "var * 3432474393 * ... * 1514376178 * R8KFFEabJ",
  "var * 2253137925 * VUx39mzbW * QoFb",
  "57676169 * var * ... * fixed_string(1464831555, 'ucs_2')",
  "var * 2859160145 * fixed_string(1233383142, 'utf-32')",
  "fixed_bytes(size=2882797968, align=4)",
  "fixed_bytes(size=1233209957, align=8)",
  "WhRsMHHXYp(categorical(145 : uint8))",
  "var * var * Z * LWfWfV6Gp6 * O8 * GWLJMYrf * 756518781 * PDVa3IbLt * bytes(align=2)",
  "categorical(-49 : int8, -26791 : int16, 1780 : uint16, -85 : int8, 'pX' : string, 8094 : int16, -400096436.783 : float64)",
  "D6nfBg_(categorical(147170982 : uint32, 16278 : int16, 208837895.375 : float32, \"ylR7\" : string, 26651 : int16))",
  "categorical(-322735020.187 : float64, 3229733591 : uint64, 482331467 : uint64, 10416529.4912 : float64)",
  /* END RANDOM */

  /* BEGIN MANUALLY GENERATED */
  "()",
  "(...)",
  "{}",
  "{...}",
  "() -> ()",
  "(...) -> ()",
  "(...) -> (...)",
  "(..., a : int64, ...) -> complex128",
  "() -> int32",
  "(int32) -> int32",
  "(int32, float64) -> int32",
  "(scale: float64) -> int32",
  "(scale: float64, color: float64) -> int32",
  "(int32, scale: float64) -> int32",
  "(int32, scale: float64, color: float64) -> int32",
  "(int32, float32, scale: float64, color: float64) -> int32",
  "(...) -> int32",
  "(int32, ...) -> int32",
  "(int32, float32, ...) -> int32",
  "(scale: float64, ...) -> int32",
  "(scale: float64, color: float64, ...) -> int32",
  "(..., scale: float64) -> int32",
  "(int32, ..., scale: float64) -> int32",
  "(int32, float32, ..., scale: float64) -> int32",
  "(int32, scale: float64, ...) -> int32",
  "(int32, float32, scale: float64, color: float64, ...) -> int32",
  "(..., scale: float64, ...) -> int32",
  "(int32, ..., scale: float64, color: float64, ...) -> int32",
  "(int32, float32, ..., scale: float64, color: float64, ...) -> int32",

  "10 * defined_t",
  "defined_t",

  "10 * foo_t",
  "foo_t",

  /* Half-float */
  "10 * float16",
  "10 * complex32",

  /* Constructor syntax for arrays */
  "10 * Matrix(3 * 2 * float64)",

  /* Attributes and metadata */
  "[10 * int32, order='C']",
  "[10 * int32, order='F']",
  "([10 * int32, order='F'], float32)",
  "([10 * int32, order='F'], float32 |pack=2|, uint8)",
  "([10 * int32, order='F'], float32, uint8, pack=2)",
  "{x : float32 |align=16|, y : float64}",

#if 0
  "[2 * 3 * int64, strides=[-8, -16]]",
  "[2 * 3 * int64, strides=[-8, -16], order='F']",
  "[10 * complex128, strides=[32]]",
#endif
  "[10 * complex128, order='F']",

#if 0
  "[2 * 3 * int64, strides=[-8, -16], offsets=[8,0]]",
  "[2 * 3 * int64, strides=[-8, -16], offsets=[0,8], order='F']",
  "[10 * complex128, strides=[32], offsets=[64]]",
  "[10 * complex128, offsets=[128], order='F']",
#endif

  "10 * var(1,2,3,4,5,6,7,8,9,10) * float64",
  "var(2) * var(3,4) * var(5,6,7,8,9,10,11) * float64",

#if 0
  "[10 * var(1,2,3,4,5,6,7,8,9,10) * float64, offsets=[0,32]]",
  "[var(2) * var(3,4) * var(5,6,7,8,9,10,11) * float64, offsets=[8,0,16]]",
#endif

  /* Ndarray */
#if 0
XXX
  "[10 * int32, order='C', style='ndarray']",
  "[10 * int32, order='F', style='ndarray']",
  "([10 * int32, order='F', style='ndarray'], float32)",
  "([10 * int32, order='F', style='ndarray'], float32 |pack=2|, uint8)",
  "([10 * int32, order='F', style='ndarray'], float32, uint8, pack=2)",

  "[2 * 3 * int64, strides=[-8, -16], offset=40, style='ndarray']",
  "[2 * 3 * int64, strides=[-8, -16], offset=40, order='F', style='ndarray']",
  "[10 * complex128, strides=[32], style='ndarray']",
  "[10 * complex128, order='F', style='ndarray']",

  "[2 * N * int64, style='ndarray']",
  "[N * 2 * int64, style='ndarray']",
  "[P * N * int64, style='ndarray']",
  "[P * N * {a: N * float64}, style='ndarray']",
#endif

  /* END MANUALLY GENERATED */

   NULL
};

