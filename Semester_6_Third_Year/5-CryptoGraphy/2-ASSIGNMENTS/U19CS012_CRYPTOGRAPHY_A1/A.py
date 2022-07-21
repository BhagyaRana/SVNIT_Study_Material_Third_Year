"""Code to Decrypt the Text {Encrypted using Caesar Cipher}
   Arguments: * Text File - File Containing the Encrypted Text
   It will generate "output.txt" File containing the Decrypted Text
   @Author - [U19CS012] {BHAGYA VINOD RANA}
"""

# For Checking if the Word is Valid in English Dictionary or Not
import enchant


def decrypt(ciphertext, key):
    """
        This function acts like a Casear Cipher.
        Replaces an input string with another string a fixed number of spaces farther down the alphabet
        Arguments:
        * ciphertext (string) - any upper case or lower case letter string
        * key (integer) - any integer value to shift to a new letter
    """
    decrypted = ""
    for c in ciphertext:
        if c.isupper():
            starting_ascii = ord('A')
            # Calculate the Alphabet Index
            alpha_index = ord(c) - starting_ascii
            # Increment it be 'key Positions'
            mod_26 = (alpha_index + key) % 26
            decrypted += chr(starting_ascii + mod_26)
        elif c.islower():
            starting_ascii = ord('a')
            # Calculate the Alphabet Index
            alpha_index = ord(c) - starting_ascii
            # Increment it be 'key Positions'
            mod_26 = (alpha_index + key) % 26
            decrypted += chr(starting_ascii + mod_26)
        else:
            decrypted += c
            # raise ValueError('Input is Not a Letter')
    return decrypted


def solve():
    """
    This will take input [Cipher Text] from input.txt & Give Decrypted Text in 'output.txt'
    """
    # Context Manager 'with' for File Input
    with open('input.txt', 'r') as f:
        # for English Dictionary
        d = enchant.Dict("en_US")
        decrypt_key = 0
        # Not used f.read()/f.readlines()/f.readline() - to Avoid Running Out of Memory
        for cryptic_text in f:

            max_valid_token = 0
            final_plain_text = ""
            final_key = 0

            # Brute Force Attack
            for i in range(0, 26):

                plain_text = decrypt(cryptic_text, i)

                # Get Tokens of the Plain Text
                plain_txt_token = plain_text.split()
                # Count the Number of Valid Tokens in Plain Text
                valid_tokens_cnt = 0
                for token in plain_txt_token:
                    if d.check(token) == True:
                        valid_tokens_cnt += 1

                # Update if the valid_token_count is maximum
                if(valid_tokens_cnt > max_valid_token):
                    final_plain_text = plain_text
                    final_key = i
                    max_valid_token = valid_tokens_cnt

            # print("For key {}, Decrypted Text:\n {} \n".format(final_key, final_plain_text))
            decrypt_key = final_key

            with open("output.txt", "a") as output_file:
                output_file.write(final_plain_text)
        print("Decryption Key for Caesar Cipher : {}\n".format(decrypt_key))


# Call to main solve() Function
if __name__ == "__main__":
    solve()
