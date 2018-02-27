/**
 * Copyright (C) 2015-2018
 * All rights reserved.
 *
 * AUTHOR(S)
 *   Zheng Shuxin
 *   E-mail: shuxin.zheng@qq.com
 * 
 * VERSION
 *   Tue 27 Feb 2018 09:11:38 PM CST
 */

#ifndef FIBER_SEM_INCLUDE_H
#define FIBER_SEM_INCLUDE_H

#include "fiber_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/* fiber semaphore */

typedef struct ACL_FIBER_SEM ACL_FIBER_SEM;

/**
 * ����Э���ź�����ͬʱ�ڲ��Ὣ��ǰ�߳�����ź�����
 * @param num {int} �ź�����ʼֵ������ >= 0��
 * @return {ACL_FIBER_SEM *}
 */
FIBER_API ACL_FIBER_SEM* acl_fiber_sem_create(int num);

/**
 * �ͷ�Э���ź���
 * @param {ACL_FIBER_SEM *}
 */
FIBER_API void acl_fiber_sem_free(ACL_FIBER_SEM* sem);

/**
 * ��õ�ǰЭ���ź������󶨵��߳� ID
 * @param sem {ACL_FIBER_SEM*} Э���ź�������
 * @return {unsigned long}
 */
#if !defined(_WIN32) && !defined(_WIN64)
FIBER_API unsigned long acl_fiber_sem_get_tid(ACL_FIBER_SEM* sem);
#endif

/**
 * ����ָ��Э���ź����ĵ��߳� ID�����ı䱾Э���ź����������߳�ʱ����ȴ���Э��
 * ���ݷ� 0 ���ڲ��Զ� fatal������Э���ź����ϵȴ�Э�̷ǿ�ʱ��ֹ���ñ�����
 * @param sem {ACL_FIBER_SEM*} Э���ź�������
 * @param {unsigned long} �߳� ID
 */
FIBER_API void acl_fiber_sem_set_tid(ACL_FIBER_SEM* sem, unsigned long tid);

/**
 * ��Э���ź��� > 0 ʱʹ�ź����� 1������ȴ��ź��� > 0
 * @param sem {ACL_FIBER_SEM *}
 * @retur {int} �����ź�����ǰֵ��������� -1 ������ǰ�߳���Э���ź��������߳�
 *  ����ͬһ�̣߳���ʱ�÷������ȴ���������
 */
FIBER_API int acl_fiber_sem_wait(ACL_FIBER_SEM* sem);

/**
 * ����ʹЭ���ź����� 1
 * @param sem {ACL_FIBER_SEM *}
 * @retur {int} �ɹ��� 1 ʱ����ֵ >= 0������ -1 ��ʾ��ǰ�ź��������ã���ǰ
 *  �������߳���Э���ź��������̲߳���ͬһ�߳�
 */
FIBER_API int acl_fiber_sem_trywait(ACL_FIBER_SEM* sem);

/**
 * ʹЭ���ź����� 1
 * @param sem {ACL_FIBER_SEM *}
 * @retur {int} �����ź�����ǰֵ������ -1 ��ʾ��ǰ�������߳���Э���ź�������
 *  �̲߳���ͬһ�߳�
 */
FIBER_API int acl_fiber_sem_post(ACL_FIBER_SEM* sem);

/**
 * ���ָ��Э���ź����ĵ�ǰֵ����ֵ��ӳ��Ŀǰ�ȴ����ź���������
 * @param sem {ACL_FIBER_SEM*}
 * @retur {int}
 */
FIBER_API int acl_fiber_sem_num(ACL_FIBER_SEM* sem);

#ifdef __cplusplus
}
#endif

#endif
