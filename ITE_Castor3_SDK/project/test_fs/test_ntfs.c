#include <sys/ioctl.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include "ite/itp.h"
#include "ntfs/ntfs.h"
#include "ntfs/iosupport.h"

static void list(const char *path, int depth)
{
    DIR *pdir;
    struct dirent *pent;
    struct stat st;
    char indent[PATH_MAX] = {0};
    char new_path[PATH_MAX] = {0};

    // Open the directory
    pdir = opendir(path);
    if (pdir) {

        // Make this our current directory
        chdir(path);

        // Build a directory indent (for better readability)
        memset(indent, ' ', depth * 2);

        // List the contents of the directory
        while ((pent = readdir(pdir)) != NULL) {
            if ((strcmp(pent->d_name, ".") == 0) || (strcmp(pent->d_name, "..") == 0))
                continue;

            // Get the entries stats
            if (stat(pent->d_name, &st) == -1)
                continue;

            // List the entry
            if (S_ISDIR(st.st_mode)) {
                printf(" D %s%s/\n", indent, pent->d_name);

                // List the directories contents
                sprintf(new_path, "%s/%s", path, pent->d_name);
                list(new_path, depth + 1);
                chdir(path);

            } else if (S_ISREG(st.st_mode)) {
                printf(" F %s%s (%lu)\n", indent, pent->d_name, (unsigned long int)st.st_size);
            } else {
                printf(" ? %s%s\n", indent, pent->d_name);
            }

        }

        // Close the directory
        closedir(pdir);

    } else {
        printf("opendir(%s) failure.\n", path);
    }

    return;
}

void* TestFunc(void* arg)
{
    ITPPartition par;

    // init pal
    itpInit();

    sleep(5);

#if 0
    par.disk = ITP_DISK_MSC00;
    par.count = 1;
    par.size[0] = 100000;
    par.start[0] = 0;
    ioctl(ITP_DEVICE_NTFS, ITP_IOCTL_CREATE_PARTITION, (void*)&par);
#else
    list("A:/", 0);
    ioctl(ITP_DEVICE_DRIVE, ITP_IOCTL_UNMOUNT, NULL);
#endif // 0

    while (1)
        sleep(1);

    return NULL;
}
