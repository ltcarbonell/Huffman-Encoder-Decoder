# Huffman-Encoder-Decoder

Your code must be able to run in CISE `storm.cise.ufl.edu` or `thunder.cise.ufl.edu` server.
Write a Makefile so that we can build your code using following command at terminal:

``` bash
$ make
```

This command should produce two binary files: `encoder` and `decoder`.
As mentioned before, encoder should take one input file. We will run it using following command:

``` bash
$ ./encoder <input_file_name> [For C++]
```

Running encoder program must produce the output files with exact name `encoded.bin` and `code_table.txt`.

On the other hand, decoder will take two input files. We will run it using following command:
``` bash
$ ./decoder <encoded_file_name> <code_table_file_name> [For C++]
```

Running decoder program must produce output file with exact name `decoded.txt`.
