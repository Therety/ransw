# ransw
Simple ransomware designed to be used for educational purposes. This malware is the simplest version of a ransomware (without the "ransom" part), where, by using XOR encryption (its a symmetric encryption, thus from encryption algorithm -> decryption), program will loop though each file located on users desktop, encrypt it and overwrite the old file with the new encrypted version (ignoring any other directory).

The whole code is in C, so it is as close to hardware, as it gets (assuming, you are not trying to build it in Assembly).

 I am not responsible for any harm caused by this sample, as it uses the simplest encryption method && as mentioned on top, the code is only for educational purposes, especially for students, that are learning about malware and its behavior.
