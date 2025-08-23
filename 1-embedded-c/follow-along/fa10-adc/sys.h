//sys.h
#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
 extern "C" {
#endif

#define LED_DEBUG_PIN     13
#define LED_BLUE_PIN       6
#define LED_YELLOW_PIN     4
#define LED_RED_PIN        8
#define SW1_PIN            2
#define SYS_SUCCESS        0
#define SYS_ERROR_1         (SYS_ERROR_BASE + 1)
#define SYS_ERROR_2         (SYS_ERROR_BASE + 1)
#define SYS_Error_Check(err) if((SYS_ERROR_NUM = (err))!=0) SYS_Fatal_Error(SYS_ERROR_NUM, __LINE__, __FILE__)
#define POT_PIN            0


extern int32_t SYS_ERROR_NUM;
extern volatile uint64_t SYS_TICK;
extern int32_t SYS_Init(void);
extern void SYS_Fatal_Error(int32_t err, int32_t line, char* file);

#ifdef __cplusplus
}

#endif // __SYS_H__
#endif
