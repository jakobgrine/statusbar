#ifndef __COMMON_H
#define __COMMON_H

#include <stdbool.h>

#define BLOCK_OUTPUT_LENGTH 8192

typedef enum {
#ifndef NO_X
    MODE_X,
#endif // NO_X
    MODE_STDOUT,
} Mode;

typedef struct {
    bool no_delimiter;
    union {
        struct {
            const char *format;
            char *command;
        } command;
        struct {
            char *text;
        } text;
        struct {
            bool all_monitors;
        } bspwm;
        struct {
            const char *format;
            char *driver;
        } backlight;
    };
} Argument;

typedef struct Block {
    unsigned int interval;
    int signal;
    void (*init)();
    void (*render)(const Argument *argument, char *output);
    void (*poll)(const Argument *argument, char *output);
    void (*deinit)();
    const Argument argument;
} Block;

#endif // __COMMON_H

