/* 
 * File:   main.c
 * Author: Oleksandr Tkachenko <oleksandr.tkachenko at crisp-da.de>
 *
 * Created on May 7, 2016, 1:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#include "psi_structures.h"
#include "psi_cuckoo_hashing.h"
#include "psi_misc.h"

int parse_argv(int argc, char** argv, PSI_CUCKOO_HASHING_CTX* ctx);

int main(int argc, char** argv) {
    PSI_CUCKOO_HASHING_CTX ctx[1];
    parse_argv(argc, argv, ctx);
    psi_cuckoo_hashing(ctx);
    return (EXIT_SUCCESS);
}

int parse_argv(int argc, char** argv, PSI_CUCKOO_HASHING_CTX* ctx) {
    int index, c;
    opterr = 0;
    ctx->hash_n = 0;
    while ((c = getopt(argc, argv, "1:2:p:e:b:s:l:t:g:r:")) != -1)
        switch (c) {
            case '1':
                atob(optarg, ctx->seed[ctx->hash_n]);
                ctx->hash_n++;
                break;
            case '2':
                atob(optarg, ctx->seed[ctx->hash_n]);
                ctx->hash_n++;
                break;
            case '3':
                atob(optarg, ctx->seed[ctx->hash_n]);
                ctx->hash_n++;
                break;
            case 'l':
                ctx->rec_limit = atoi(optarg);
                break;
            case 'b':
                ctx->d_mult_size_table = atof(optarg);
                break;
            case 'e':
                ctx->element_pow = atoi(optarg);
                break;
            case 'p':
                strncpy(ctx->path_source, optarg, 128);
                break;
            case 'r':
                ctx->read_buffer_size = atoi(optarg);
                break;
            case 't':
                strncpy(ctx->path_dest, optarg, 128);
                break;
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
                exit(EXIT_FAILURE);
            default:
                abort();
        }

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
}

