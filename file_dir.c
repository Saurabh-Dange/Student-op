/*****************************************************************************
 *   PROJECT  :print the names of files of all directories starting from root*
 *   FILE_NAME:file_dir.c                                                  *
 *   VERSION  :1.0.0                                                         *
 *   DATE     :19/06/2017                                                    *
 *                                                                           *
 *	 Saurabh S Dange ©                                                       *
 *   All rights reserved                                                     *
 *****************************************************************************/

#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>



#ifndef USE_FDS
#define USE_FDS 15
#endif

int display(const char *filepath, const struct stat *info,
                const int typeflag, struct FTW *pathinfo)
{



    if (typeflag == FTW_SL) {
        char   *target;
        size_t  maxlen = 1023;
        ssize_t len;

        while (1) {

            target = malloc(maxlen + 1);
            if (target == NULL)
                return ENOMEM;

            len = readlink(filepath, target, maxlen);
            if (len == (ssize_t)-1) {
                const int saved_errno = errno;
                free(target);
                return saved_errno;
            }
            if (len >= (ssize_t)maxlen) {
                free(target);
                maxlen += 1024;
                continue;
            }

            target[len] = '\0';
            break;
        }

        printf(" %s -> %s\n", filepath, target);
        free(target);

    } else
    if (typeflag == FTW_SLN)
        printf(" %s (dangling symlink)\n", filepath);
    else
    if (typeflag == FTW_F)
        printf(" %s\n", filepath);
    else
    if (typeflag == FTW_D || typeflag == FTW_DP)
        printf(" %s/\n", filepath);
    else
    if (typeflag == FTW_DNR)
        printf(" %s/ (unreadable)\n", filepath);
    else
        printf(" %s (unknown)\n", filepath);

    return 0;
}


int print_tree(const char *const dirpath)
{
    int result;

    /* Invalid directory path? */
    if (dirpath == NULL || *dirpath == '\0')
        return errno = EINVAL;

    result = nftw(dirpath, display, USE_FDS, FTW_PHYS);
    if (result >= 0)
        errno = result;

    return errno;
}

int main(int argc, char *argv[])
{
    int arg;

    if (argc < 2) {

        if (print_tree("/")) {
            fprintf(stderr, "%s.\n", strerror(errno));
            return EXIT_FAILURE;
        }

    } else {

        for (arg = 1; arg < argc; arg++) {
            if (print_tree("/")) {
                fprintf(stderr, "%s.\n", strerror(errno));
                return EXIT_FAILURE;
            }
        }

    }

    return EXIT_SUCCESS;
}
