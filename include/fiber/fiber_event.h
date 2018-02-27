/**
 * Copyright (C) 2015-2018
 * All rights reserved.
 *
 * AUTHOR(S)
 *   Zheng Shuxin
 *   E-mail: shuxin.zheng@qq.com
 * 
 * VERSION
 *   Tue 27 Feb 2018 09:09:24 PM CST
 */

#ifndef FIBER_EVENT_INCLUDE_H
#define FIBER_EVENT_INCLUDE_H

#include "fiber_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/* fiber_event.c */

/* �̰߳�ȫ��Э�������������ڲ�ͬ�̵߳�Э��֮�估��ͬ�߳�֮��Ļ��� */
typedef struct ACL_FIBER_EVENT ACL_FIBER_EVENT;

/**
 * ���������¼���Э��/�̻߳����
 * @return {ACL_FIBER_EVENT *}
 */
FIBER_API ACL_FIBER_EVENT *acl_fiber_event_create(void);

/**
 * �ͷ��¼���
 * @param {ACL_FIBER_EVENT *}
 */
FIBER_API void acl_fiber_event_free(ACL_FIBER_EVENT *event);

/**
 * �ȴ��¼�������
 * @param {ACL_FIBER_EVENT *}
 * @return {int} ���� 0 ��ʾ�ɹ���-1 ��ʾ����
 */
FIBER_API int acl_fiber_event_wait(ACL_FIBER_EVENT *event);

/**
 * ���Եȴ��¼�������
 * @param {ACL_FIBER_EVENT *}
 * @return {int} ���� 0 ��ʾ�ɹ���-1 ��ʾ����ռ��
 */
FIBER_API int acl_fiber_event_trywait(ACL_FIBER_EVENT *event);

/**
 * �¼���ӵ����֪ͨ�ȴ����¼������ã���ȴ����յ�֪ͨ����ɻ���¼���
 * @param {ACL_FIBER_EVENT *}
 * @return {int} ���� 0 ��ʾ�ɹ���-1 ��ʾ����
 */
FIBER_API int acl_fiber_event_notify(ACL_FIBER_EVENT *event);

#ifdef __cplusplus
}
#endif

#endif
