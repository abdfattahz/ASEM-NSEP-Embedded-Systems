// sys.h
#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LED_DEBUG_PIN     13
#define LED_DEBUG_PIN2    11
#define LED_DEBUG_PIN3     8
#define LED_DEBUG_PIN4     2

#define SYS_SUCCESS           0

#define SYS_Error_Check(fn_call)                 \
    do {                                         \
        int32_t err = (fn_call);                 \
        if (err != 0)                            \
            SYS_Fatal_Error(err);                \
    } while (0)

extern int32_t SYS_ERROR_NUM;
extern uint64_t SYS_TICK;

void SYS_Init(void);
void SYS_Fatal_Error(int32_t err);

#ifdef __cplusplus
}

#endif // __SYS_H__
#endif
