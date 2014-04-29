## openssl-compare
Download, build and compare OpenSSL versions for testing, fuzzing [...] 

### Howto
initially download, verify and extract all OpenSSL tarballs:
```bash
./init 

# alternatively download, verify, extract and build:
./init -b
```
build all OpenSSL versions:
```bash
./build
```

clean all OpenSSL versions:
```bash
./init -c

# alternatively:
./clean
```

remove all OpenSSL versions:
```
./init -w
```

test a Ciphersuite among all versions:
```bash
./cmp_ciphersuite -s DES
openssl-compare::cmp_ciphersuite >> testing Ciphersuite: DES on work/openssl-0.9.8o/apps/openssl
ADH-DES-CBC-SHA         SSLv3 Kx=DH       Au=None Enc=DES(56)   Mac=SHA1
DES-CBC-MD5             SSLv2 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=MD5 
DES-CBC-SHA             SSLv3 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=SHA1
EDH-DSS-DES-CBC-SHA     SSLv3 Kx=DH       Au=DSS  Enc=DES(56)   Mac=SHA1
EDH-RSA-DES-CBC-SHA     SSLv3 Kx=DH       Au=RSA  Enc=DES(56)   Mac=SHA1
EXP-ADH-DES-CBC-SHA     SSLv3 Kx=DH(512)  Au=None Enc=DES(40)   Mac=SHA1 export
EXP-DES-CBC-SHA         SSLv3 Kx=RSA(512) Au=RSA  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-DSS-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=DSS  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-RSA-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=RSA  Enc=DES(40)   Mac=SHA1 export
openssl-compare::cmp_ciphersuite >> testing Ciphersuite: DES on work/openssl-0.9.8p/apps/openssl
ADH-DES-CBC-SHA         SSLv3 Kx=DH       Au=None Enc=DES(56)   Mac=SHA1
DES-CBC-MD5             SSLv2 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=MD5 
DES-CBC-SHA             SSLv3 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=SHA1
EDH-DSS-DES-CBC-SHA     SSLv3 Kx=DH       Au=DSS  Enc=DES(56)   Mac=SHA1
EDH-RSA-DES-CBC-SHA     SSLv3 Kx=DH       Au=RSA  Enc=DES(56)   Mac=SHA1
EXP-ADH-DES-CBC-SHA     SSLv3 Kx=DH(512)  Au=None Enc=DES(40)   Mac=SHA1 export
EXP-DES-CBC-SHA         SSLv3 Kx=RSA(512) Au=RSA  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-DSS-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=DSS  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-RSA-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=RSA  Enc=DES(40)   Mac=SHA1 export
openssl-compare::cmp_ciphersuite >> testing Ciphersuite: DES on work/openssl-0.9.8q/apps/openssl
ADH-DES-CBC-SHA         SSLv3 Kx=DH       Au=None Enc=DES(56)   Mac=SHA1
DES-CBC-MD5             SSLv2 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=MD5 
DES-CBC-SHA             SSLv3 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=SHA1
EDH-DSS-DES-CBC-SHA     SSLv3 Kx=DH       Au=DSS  Enc=DES(56)   Mac=SHA1
EDH-RSA-DES-CBC-SHA     SSLv3 Kx=DH       Au=RSA  Enc=DES(56)   Mac=SHA1
EXP-ADH-DES-CBC-SHA     SSLv3 Kx=DH(512)  Au=None Enc=DES(40)   Mac=SHA1 export
EXP-DES-CBC-SHA         SSLv3 Kx=RSA(512) Au=RSA  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-DSS-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=DSS  Enc=DES(40)   Mac=SHA1 export
EXP-EDH-RSA-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=RSA  Enc=DES(40)   Mac=SHA1 export
[...]
```

same thing with `diff(1)` output:
```bash
./cmp_ciphersuite -s AES -d

[...]
openssl-0.9.8o and openssl-1.0.0i differ
openssl-0.9.8o and openssl-1.0.0j differ
openssl-0.9.8o and openssl-1.0.0k differ
openssl-0.9.8o and openssl-1.0.0l differ
[...]
openssl-0.9.8o and openssl-1.0.1f differ
openssl-0.9.8o and openssl-1.0.1g differ
openssl-0.9.8o and openssl-1.0.2-beta1 differ
openssl-0.9.8p and openssl-1.0.0a differ
openssl-0.9.8p and openssl-1.0.0 differ
openssl-0.9.8p and openssl-1.0.0b differ
openssl-0.9.8p and openssl-1.0.0-beta5 differ
[...]
openssl-1.0.1f and openssl-1.0.1b differ
openssl-1.0.1f and openssl-1.0.1-beta1 differ
openssl-1.0.1f and openssl-1.0.1-beta2 differ
openssl-1.0.1f and openssl-1.0.1-beta3 differ
openssl-1.0.1f and openssl-1.0.1c differ
openssl-1.0.1f and openssl-1.0.2-beta1 differ
openssl-1.0.1f and openssl-fips-1.1.2 differ
openssl-1.0.1g and openssl-0.9.8o differ
openssl-1.0.1g and openssl-0.9.8p differ
openssl-1.0.1g and openssl-0.9.8q differ
openssl-1.0.1g and openssl-0.9.8r differ
openssl-1.0.1g and openssl-0.9.8s differ
openssl-1.0.1g and openssl-0.9.8t differ
openssl-1.0.1g and openssl-0.9.8u differ
[...]
```
"enjoy".

(more coming soon)

**Not all OpenSSL versions will compile out of the box with your default system GCC and glibc!**

#### Using different compiler versions
Manually set the appropriate environment variables to the paths of your prefered compiler(s). Or take a look at how Environment modules (in particular Lmod) work. 

https://en.wikipedia.org/wiki/Environment_Modules_(software)
https://github.com/TACC/Lmod

### Todo
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

