# ransw
Simple ransomware designed to be used for educational purposes. This malware is the simplest version of a ransomware (without the "ransom" part), where, by using XOR encryption, program will loop though each file located on users desktop, encrypt it's binary form and overwrite the old file with the new encrypted version (ignoring any other directory).

The whole code is in C, so it is as close to hardware, as it gets (assuming, you are not trying to build it in Assembly).

## XOR Encryption
Pretty much the simplest encryption algorithm, where the XOR is a logical operator that takes 2 bits and outputs 1 (The symbol "^" in the code down bellow represents the XOR operation). It is a simmetric algorithm, which means, that same key and function used for encryption, works for decryption.

```c
for (int i = 0; i < fileSize; i++) {
  buffer[i] = buffer[i] ^ key[i % strlen(key)];
}
```

However, this type of encryption algorithm is very weak and reversible, thus i do not recommend using it.

## Disclaimer
I am not responsible for any harm caused by this sample, as it uses the simplest encryption method && as mentioned on top, the code is only for educational purposes, especially for students, that are learning about malware and its behavior. Feel free to modify my code.
