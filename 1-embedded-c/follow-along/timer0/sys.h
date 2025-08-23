//sys.h
#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LED_DEBUG_PIN     13
#define LED_BLUE_PIN      11
#define LED_YELLOW_PIN     8
#define LED_RED_PIN        2
#define SW1_PIN            3

#define SYS_SUCCESS        0

#define SYS_Error_Check(fn_call)             \
  do {                                       \
    int32_t err = (fn_call);                 \
    if (err != 0)                            \
      SYS_Fatal_Error(err);                  \
  } while (0)

extern int32_t SYS_ERROR_NUM;
extern volatile uint64_t SYS_TICK;

#define SYS_Error_Check(x) if((SYS_ERROR_NUM = (x)) != 0) SYS_Fatal_Error (SYS_ERROR_NUM, __LINE__, __FILE__)
void SYS_Fatal_Error(int32_t err, int32_t line, char* file);
int32_t SYS_Init(void);

#ifdef __cplusplus
}

#endif // __SYS_H__
#endif
