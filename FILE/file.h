#ifndef H_FILE
#define H_FILE

#define PUBLIC_KEY_FILE_NAME     ((const P_USTR)"RESOURCES/public.key")
#define PRIVATE_KEY_FILE_NAME     ((const P_USTR)"RESOURCES/private.key")

STATUT_CODE file_to_buff(P_STR file_path, P_STR file_buffer);

STATUT_CODE load_pubkey(P_STR input_file_private_key, P_STR input_file_public_key, RSA* pRSA);

STATUT_CODE create_rsa_keys_files(P_STR input_file_private_key, P_STR input_file_public_key, RSA* pRSA);

#endif
