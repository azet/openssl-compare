# openssl-compare
download, build and compare OpenSSL versions for testing, fuzzing, lulz [...]

## Howto
#### initially download, verify and extract all OpenSSL tarballs
```bash
./openssl-compare init
```

#### build all OpenSSL versions
```bash
./openssl-compare build
```

#### clean all OpenSSL versions
```bash
./openssl-compare clean
```

#### remove all OpenSSL versions
```bash
./openssl-compare init -w
```

#### test a ciphersuite among all versions
```bash
./openssl-compare ciphersuite -s DES
openssl-compare::cmp_ciphersuite >> testing Ciphersuite: DES on work/openssl-0.9.8o/apps/openssl
ADH-DES-CBC-SHA         SSLv3 Kx=DH       Au=None Enc=DES(56)   Mac=SHA1
DES-CBC-MD5             SSLv2 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=MD5 
DES-CBC-SHA             SSLv3 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=SHA1
EDH-DSS-DES-CBC-SHA     SSLv3 Kx=DH       Au=DSS  Enc=DES(56)   Mac=SHA1
[...]
openssl-compare::cmp_ciphersuite >> testing Ciphersuite: DES on work/openssl-0.9.8q/apps/openssl
ADH-DES-CBC-SHA         SSLv3 Kx=DH       Au=None Enc=DES(56)   Mac=SHA1
DES-CBC-MD5             SSLv2 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=MD5 
DES-CBC-SHA             SSLv3 Kx=RSA      Au=RSA  Enc=DES(56)   Mac=SHA1
EDH-DSS-DES-CBC-SHA     SSLv3 Kx=DH       Au=DSS  Enc=DES(56)   Mac=SHA1
EXP-EDH-RSA-DES-CBC-SHA SSLv3 Kx=DH(512)  Au=RSA  Enc=DES(40)   Mac=SHA1 export
[...]
```

#### `diff(1)` a ciphersuite among many versions
```bash
./openssl-compare ciphersuite -s AES -d

[...]
openssl-0.9.8o and openssl-1.0.0i differ
[...]
openssl-0.9.8p and openssl-1.0.0-beta5 differ
[...]
openssl-1.0.1f and openssl-1.0.1b differ
openssl-1.0.1g and openssl-0.9.8u differ
[...]
```

#### compare ciphersuite negotiation and preference among OpenSSL versions:
```bash
 ./openssl-compare nagotiate -s 'ALL:!ADH:RC4+RSA:+HIGH:+MEDIUM:-LOW:-SSLv2:-EXP'
 openssl-compare::openssl-compare >> starting s_server for work/openssl-0.9.8o/apps/openssl
 openssl-compare::openssl-compare >> starting s_client for work/openssl-0.9.8o/apps/openssl
 openssl-compare::openssl-compare >> killing off s_server listener:
 lib/nagotiate: line 48:  4095 Terminated              LD_PRELOAD=${runpath}/lib/bio_printf_wrapper.so ./openssl s_server -state -debug -msg -accept ${port} -cipher ${suite} -serverpref -cert ${runpath}/share/cert.pem -key ${runpath}/share/key.pem &>> /tmp/${openssl//\//_}_srv
 openssl-compare::openssl-compare >> nagotiated ciphersuite:
 Shared ciphers:DHE-RSA-AES256-SHA:DHE-DSS-AES256-SHA:AES256-SHA:EDH-RSA-DES-CBC3-SHA:EDH-DSS-DES-CBC3-SHA:DES-CBC3-SHA:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA:AES128-SHA:IDEA-CBC-SHA:RC4-SHA:RC4-MD5:EDH-RSA-DES-CBC-SHA:EDH-DSS-DES-CBC-SHA:DES-CBC-SHA:EXP-EDH-RSA-DES-CBC-SHA:EXP-EDH-DSS-DES-CBC-SHA:EXP-DES-CBC-SHA:EXP-RC2-CBC-MD5:EXP-RC4-MD5
 CIPHER is DHE-RSA-AES256-SHA

[...]

openssl-compare::openssl-compare >> starting s_server for work/openssl-1.0.0-beta5/apps/openssl
openssl-compare::openssl-compare >> starting s_client for work/openssl-1.0.0-beta5/apps/openssl
openssl-compare::openssl-compare >> killing off s_server listener:
lib/nagotiate: line 48:  4285 Terminated              LD_PRELOAD=${runpath}/lib/bio_printf_wrapper.so ./openssl s_server -state -debug -msg -accept ${port} -cipher ${suite} -serverpref -cert ${runpath}/share/cert.pem -key ${runpath}/share/key.pem &>> /tmp/${openssl//\//_}_srv
openssl-compare::openssl-compare >> nagotiated ciphersuite:
Shared ciphers:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:ECDH-RSA-AES256-SHA:ECDH-ECDSA-AES256-SHA:AES256-SHA:CAMELLIA256-SHA:ECDHE-RSA-DES-CBC3-SHA:ECDHE-ECDSA-DES-CBC3-SHA:EDH-RSA-DES-CBC3-SHA:EDH-DSS-DES-CBC3-SHA:ECDH-RSA-DES-CBC3-SHA:ECDH-ECDSA-DES-CBC3-SHA:DES-CBC3-SHA:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA:DHE-RSA-SEED-SHA:DHE-DSS-SEED-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA:ECDH-RSA-AES128-SHA:ECDH-ECDSA-AES128-SHA:AES128-SHA:SEED-SHA:CAMELLIA128-SHA:IDEA-CBC-SHA:ECDHE-RSA-RC4-SHA:ECDHE-ECDSA-RC4-SHA:ECDH-RSA-RC4-SHA:ECDH-ECDSA-RC4-SHA:RC4-SHA:RC4-MD5:EDH-RSA-DES-CBC-SHA:EDH-DSS-DES-CBC-SHA:DES-CBC-SHA:EXP-EDH-RSA-DES-CBC-SHA:EXP-EDH-DSS-DES-CBC-SHA:EXP-DES-CBC-SHA:EXP-RC2-CBC-MD5:EXP-RC4-MD5
CIPHER is ECDHE-RSA-AES256-SHA

[...]
```


"enjoy"



*Not all OpenSSL versions will compile out of the box with your default system GCC and glibc!*

## Using different compiler versions
Manually set the appropriate environment variables to the paths of your prefered compiler(s). Or take a look at how Environment modules (in particular Lmod) work. 

https://en.wikipedia.org/wiki/Environment_Modules_(software)    
https://github.com/TACC/Lmod

## Todo
* per file/branch diff

## License
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

