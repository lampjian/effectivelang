# encryption
openssl enc -aes-128-ecb -e -in myfile -out myfile-aes

# decryption
openssl enc -aes-128-ecb -d -in myfile-aes -out myfile

