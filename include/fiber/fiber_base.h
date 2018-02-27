#ifndef FIBER_BASE_INCLUDE_H
#define FIBER_BASE_INCLUDE_H

#include "fiber_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * �����Ƿ���Ҫ hook ϵͳ�е� IO ��ص� API���ڲ�ȱʡֵΪ 1
 * @param onoff {int} �Ƿ���Ҫ hook
 */
FIBER_API void acl_fiber_hook_api(int onoff);

/**
 * ����һ��Э��
 * @param fn {void (*)(ACL_FIBER*, void*)} Э������ʱ�Ļص�������ַ
 * @param arg {void*} �ص� fn ����ʱ�ĵڶ�������
 * @param size {size_t} ������Э����ռջ�ռ��С
 * @return {ACL_FIBER*}
 */
FIBER_API ACL_FIBER* acl_fiber_create(void (*fn)(ACL_FIBER*, void*),
	void* arg, size_t size);

/**
 * ���ص�ǰ�߳��д�������״̬��Э����
 * @retur {int}
 */
FIBER_API int acl_fiber_ndead(void);

FIBER_API void acl_fiber_check_timer(size_t max);

/**
 * ���ص�ǰ�������е�Э�̶���
 * @retur {ACL_FIBER*} ���� NULL ��ʾ��ǰû���������е�Э��
 */
FIBER_API ACL_FIBER* acl_fiber_running(void);

/**
 * �������Э�̵�Э�� ID ��
 * @param fiber {const ACL_FIBER*} acl_fiber_create ������Э�̶��󣬱���ǿ�
 * @return {unsigned int} Э�� ID ��
 */
FIBER_API unsigned int acl_fiber_id(const ACL_FIBER* fiber);

/**
 * ��õ�ǰ�����е�Э�̵� ID ��
 * @return {unsigned int} ��ǰ����Э�̵� ID ��
 */
FIBER_API unsigned int acl_fiber_self(void);

/**
 * ��������Э�̵Ĵ����
 * @param fiber {ACL_FIBER*} ָ����Э�̶���Ϊ NULL ��ʹ�õ�ǰ���е�Э��
 * @param errnum {int} �����
 */
FIBER_API void acl_fiber_set_errno(ACL_FIBER* fiber, int errnum);

/**
 * ���ָ��Э�̵Ĵ����
 * @param fiber {ACL_FIBER*} ָ����Э�̶�����Ϊ NULL ��ʹ�õ�ǰЭ�̶���
 * @return {int} ����Э�̴����
 */
FIBER_API int acl_fiber_errno(ACL_FIBER* fiber);

/**
 * ��õ�ǰϵͳ���� errno ��
 * @return {int}
 */
FIBER_API int acl_fiber_sys_errno(void);

/**
 * ���õ�ǰϵͳ�� errno ��
 * @param errnum {int}
 */
FIBER_API void acl_fiber_sys_errno_set(int errnum);

/**
 * �Ƿ񱣳���ָ��Э�̵Ĵ���ţ�������Ϊ�����֡������Э�̽����ֵ�ǰ״̬�µ�
 * ����ţ�֮���Э�̵Ĵ���� errno �����ٸı䣬�ߵ��ٴε��ñ�����ȡ������
 * @param fiber {ACL_FIBER*} ָ����Э�̶���Ϊ NULL ��ʹ�õ�ǰ���е�Э��
 * @param yesno {int} �Ƿ񱣳�
 */
FIBER_API void acl_fiber_keep_errno(ACL_FIBER* fiber, int yesno);

/**
 * ���ָ��Э�̵ĵ�ǰ״̬
 * @param fiber {const ACL_FIBER*} ָ����Э�̶���Ϊ NULL ��ʹ�õ�ǰЭ��
 * @return {int} Э��״̬
 */
FIBER_API int acl_fiber_status(const ACL_FIBER* fiber);

/**
 * ֪ͨ��������״̬��Э���˳� 
 * @param fiber {const ACL_FIBER*} ָ����Э�̶��󣬱���� NULL
 */
FIBER_API void acl_fiber_kill(ACL_FIBER* fiber);

/**
 * ��鱾Э���Ƿ�����Э��֪ͨ�˳�
 * @param fiber {const ACL_FIBER*} ָ����Э�̶�����Ϊ NULL ���Զ�ʹ�õ�ǰ
 *  �������е�Э��
 * @return {int} ����ֵΪ 0 ��ʾû�б�֪ͨ�˳����� 0 ��ʾ��֪ͨ�˳�
 */
FIBER_API int acl_fiber_killed(ACL_FIBER* fiber);

/**
 * ������ IO ��ԭ�������ߵ�Э��
 * @param fiber {const ACL_FIBER*} Э�̶��󣬱���� NULL
 * @param signum {int} SIGINT, SIGKILL, SIGTERM ... �ο�ϵͳ�� bits/signum.h
 */
FIBER_API void acl_fiber_signal(ACL_FIBER* fiber, int signum);

/**
 * �������Э�̷��͸�ָ��Э�̵��ź�ֵ
 * @param fiber {const ACL_FIBER*} ָ����Э�̶���Ϊ NULL ʱ��ʹ�õ�ǰЭ��
 * @retur {int} ����ָ��Э���յ����ź�ֵ
 */
FIBER_API int acl_fiber_signum(ACL_FIBER* fiber);

/**
 * ����ǰ���е�Э�̹����ɵ�����ѡ����һ����Ҫ���е�Э��
 * @return {int}
 */
FIBER_API int acl_fiber_yield(void);

/**
 * ��ָ��Э�̶�����������ж�����
 * @param fiber {ACL_FIBER*} ָ��Э�̣������ NULL
 */
FIBER_API void acl_fiber_ready(ACL_FIBER* fiber);

/**
 * ����ǰ���е�Э�̹���ͬʱִ�еȴ�������һ�������е�Э��
 */
FIBER_API void acl_fiber_switch(void);

/**
 * ���õ�ǰ�̵߳�Э�̵������Ƿ�Ϊ������ģʽ��������ģʽ��������Э�̺������
 * ����Э�̵���״̬�������Э�̵���״̬�����Զ���������������Э�̹��̣��粻
 * ���ñ����������ڲ�ȱʡΪ���Զ�����ģʽ��
 */
FIBER_API void acl_fiber_schedule_init(int on);

/**
 * ���ñ���������Э�̵ĵ��ȹ���
 */
FIBER_API void acl_fiber_schedule(void);

/**
 * ����ָ�����¼���������Э�̵��������ڲ�ȱʡ���¼�����Ϊ FIBER_EVENT_KERNEL
 * @param event_mode {int} �¼��������ͣ��μ���FIBER_EVENT_XXX
 */
#define FIBER_EVENT_KERNEL	0	/* epoll/kqueue	*/
#define FIBER_EVENT_POLL	1	/* poll		*/
#define FIBER_EVENT_SELECT	2	/* select	*/
#define FIBER_EVENT_WMSG	3	/* win message	*/
FIBER_API void acl_fiber_schedule_with(int event_mode);

/**
 * ����Э�̵���ʱ���¼���������
 * @param event_mode {int} �¼��������ͣ��μ���FIBER_EVENT_XXX
 */
FIBER_API void acl_fiber_schedule_set_event(int event_mode);

/**
 * ���ñ�������⵱ǰ�߳��Ƿ���Э�̵���״̬
 * @return {int} 0 ��ʾ��Э��״̬���� 0 ��ʾ����Э�̵���״̬
 */
FIBER_API int acl_fiber_scheduled(void);

/**
 * ֹͣЭ�̹���
 */
FIBER_API void acl_fiber_schedule_stop(void);

/**
 * ʹ��ǰ���е�Э������ָ��������
 * @param milliseconds {unsigned int} ָ��Ҫ���ߵĺ�����
 * @return {unsigned int} ��Э�����ߺ��ٴα����Ѻ�ʣ��ĺ�����
 */
FIBER_API unsigned int acl_fiber_delay(unsigned int milliseconds);

/**
 * ʹ��ǰ���е�Э������ָ������
 * @param seconds {unsigned int} ָ��Ҫ���ߵ�����
 * @return {unsigned int} ��Э�����ߺ��ٴα����Ѻ�ʣ�������
 */
FIBER_API unsigned int acl_fiber_sleep(unsigned int seconds);

/**
 * ����һ��Э��������ʱ��
 * @param milliseconds {unsigned int} ��������ʱ�������ѵĺ�����
 * @param size {size_t} ������Э�̵�ջ�ռ��С
 * @param fn {void (*)(ACL_FIBER*, void*)} ��ʱ��Э�̱�����ʱ�Ļص�����
 * @param ctx {void*} �ص� fn ����ʱ�ĵڶ�������
 * @return {ACL_FIBER*} �´����Ķ�ʱ��Э��
 */
FIBER_API ACL_FIBER* acl_fiber_create_timer(unsigned int milliseconds,
	size_t size, void (*fn)(ACL_FIBER*, void*), void* ctx);

/**
 * �ڶ�ʱ��Э��δ������ǰ������ͨ�����������ø�Э�̱����ѵ�ʱ��
 * @param timer {ACL_FIBER*} �� acl_fiber_create_timer �����Ķ�ʱ��Э��
 * @param milliseconds {unsigned int} ָ���ö�ʱ��Э�̱����ѵĺ�����
 */
FIBER_API void acl_fiber_reset_timer(ACL_FIBER* timer, unsigned int milliseconds);

/**
 * ���������� DNS �������ĵ�ַ
 * @param ip {const char*} DNS ������ IP ��ַ
 * @param port {int} DNS �������Ķ˿�
 */
FIBER_API void acl_fiber_set_dns(const char* ip, int port);

/* for fiber specific */

/**
 * �趨��ǰЭ�̵ľֲ�����
 * @param key {int*} Э�ֲ̾��������������ĵ�ַ����ʼʱ��ֵӦ <= 0���ڲ����Զ�
 *  ����һ�� > 0 ���������������õ�ַ��ֵ�������Э�̿��Ը��ø�ֵ���ø��Ե�
 *  �ֲ���������ָ������ NULL
 * @param ctx {void *} Э�ֲ̾�����
 * @param free_fn {void (*)(void*)} ��Э���˳�ʱ����ô˺����ͷ�Э�ֲ̾�����
 * @return {int} ���������õ�Э�ֲ̾������ļ�ֵ������ -1 ��ʾ��ǰЭ�̲�����
 */
FIBER_API int acl_fiber_set_specific(int* key, void* ctx, void (*free_fn)(void*));

/**
 * ��õ�ǰЭ�ֲ̾�����
 * @param key {int} �� acl_fiber_set_specific ���صļ�ֵ
 * @retur {void*} ���� NULL ��ʾ������
 */
FIBER_API void* acl_fiber_get_specific(int key);

/****************************************************************************/

/**
 * �ڽ�д��־����־�ļ�ǰ�ص��û��Զ���ĺ������ҽ���־��Ϣ���ݸ��ú�����
 * ֻ�е��û�ͨ�� msg_pre_write �������ú����Ч
 * @param ctx {void*} �û����Զ������
 * @param fmt {const char*} ��ʽ����
 * @param ap {va_list} ��ʽ�����б�
 */
typedef void (*FIBER_MSG_PRE_WRITE_FN)(void *ctx, const char *fmt, va_list ap);

/**
 * Ӧ��ͨ���˺������Ϳ����Զ�����־��¼��������Ӧ���ڴ���־ǰ����
 * msg_register ע�����Զ����¼��������Ӧ��д��־ʱ���ô��Զ���
 * ������¼��־��������ȱʡ����־��¼����
 * @param ctx {void*} Ӧ�ô��ݽ�ȥ�Ĳ���
 * @param fmt {const char*} ��ʽ����
 * @param ap {va_list} �����б�
 */
typedef void (*FIBER_MSG_WRITE_FN) (void *ctx, const char *fmt, va_list ap);

/**
 * �ڴ���־ǰ���ô˺���ע��Ӧ���Լ�����־��¼����
 * @param write_fn {MSG_WRITE_FN} �Զ�����־��¼����
 * @param ctx {void*} �Զ������
 */
FIBER_API void acl_fiber_msg_register(FIBER_MSG_WRITE_FN write_fn, void *ctx);

/**
 * �� msg_register ע���Զ��庯�����������ȱʡ����־������
 */
FIBER_API void acl_fiber_msg_unregister(void);

/**
 * �ڴ���־ǰ���ô˺���ע��Ӧ�õ�˽�к������ڼ�¼��־ǰ���ȼ�¼��Ϣͨ��
 * ��ע��ĺ������ݸ�Ӧ��
 * @param pre_write {MSG_PRE_WRITE_FN} ��־��¼ǰ���õĺ���
 * @param ctx {void*} �Զ������
 */
FIBER_API void acl_fiber_msg_pre_write(FIBER_MSG_PRE_WRITE_FN pre_write, void *ctx);

/**
 * ��δ���� msg_open ��ʽ����־ʱ�������� msg_info/error/fatal/warn
 * �Ĳ������Ƿ�������Ϣ�������׼�����Ļ�ϣ�ͨ���˺��������øÿ��أ��ÿ���
 * ��Ӱ���Ƿ���Ҫ����Ϣ������ն���Ļ����Ӱ���Ƿ�������ļ���
 * @param onoff {int} �� 0 ��ʾ�����������Ļ
 */
FIBER_API void acl_fiber_msg_stdout_enable(int onoff);

/**
 * ����ϴ�ϵͳ���ó���ʱ�Ĵ����
 * @return {int} �����
 */
FIBER_API int acl_fiber_last_error(void);

/**
 * ����ϴ�ϵͳ���ó���ʱ�Ĵ�����Ϣ
 * @return {const char*}
 */
FIBER_API const char *acl_fiber_last_serror(void);

/**
 * �ֹ����ô����
 * @param errnum {int} �����
 */
void acl_fiber_set_error(int errnum);

/****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
