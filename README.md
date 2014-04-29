## openssl-compare
Download, build and compare OpenSSL versions for testing, fuzzing [...] 

### Howto
initially download and extract all OpenSSL tarballs:
```bash
./init # optionally build with -b
```
build all OpenSSL versions:
```bash
./build
```

test a Ciphersuite among all versions:
```bash
./cmp_ciphersuite -s AES-GCM

[...]
```

same thing with diff(1) output:
```bash
./cmp_ciphersuite -s AES-GCM -d

[...]
```
"enjoy".

(more coming soon)

**Not all OpenSSL versions will compile out of the box with your default system GCC and glibc!**

#### Using different compiler versions
Manually set the appropriate environment variables to the paths of your prefered compiler(s). Or take a look at how Environment modules (in particular Lmod) work. 

[https://en.wikipedia.org/wiki/Environment_Modules_(software)]()    
[https://github.com/TACC/Lmod]()

### Todo
* cipherstring testing with multiple versions
* per file/branch diff
* proper doc

### License
```
The MIT License (MIT)

Copyright (c) 2014 Aaron Zauner <azet@azet.org>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```

