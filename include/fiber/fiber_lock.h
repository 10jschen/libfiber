/**
 * Copyright (C) 2015-2018
 * All rights reserved.
 *
 * AUTHOR(S)
 *   Zheng Shuxin
 *   E-mail: shuxin.zheng@qq.com
 * 
 * VERSION
 *   Tue 27 Feb 2018 09:05:09 PM CST
 */

#ifndef FIBER_LOCK_INCLUDE_H
#define FIBER_LOCK_INCLUDE_H

#include "fiber_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/* fiber locking */

/**
 * Э�̻��������̷߳ǰ�ȫ��ֻ������ͬһ�߳���
 */
typedef struct ACL_FIBER_MUTEX ACL_FIBER_MUTEX;

/**
 * Э�̶�д�����̷߳ǰ�ȫ��ֻ������ͬһ�߳���
 */
typedef struct ACL_FIBER_RWLOCK ACL_FIBER_RWLOCK;

/**
 * ����Э�̻��������̷߳ǰ�ȫ��ֻ������ͬһ�߳���
 * @return {ACL_FIBER_MUTEX*}
 */
FIBER_API ACL_FIBER_MUTEX* acl_fiber_mutex_create(void);

/**
 * �ͷ�Э�̻�����
 * @param l {ACL_FIBER_MUTEX*} �� acl_fiber_mutex_create ������Э�̻�����
 */
FIBER_API void acl_fiber_mutex_free(ACL_FIBER_MUTEX* l);

/**
 * ��Э�̻�������������ʽ��������������ɹ��򷵻أ�����������
 * @param l {ACL_FIBER_MUTEX*} �� acl_fiber_mutex_create ������Э�̻�����
 */
FIBER_API void acl_fiber_mutex_lock(ACL_FIBER_MUTEX* l);

/**
 * ��Э�̻����������Խ��м����������Ƿ�ɹ�����������������
 * @param l {ACL_FIBER_MUTEX*} �� acl_fiber_mutex_create ������Э�̻�����
 * @return {int} ��������ɹ��򷵻� 0 ֵ�����򷵻� -1
 */
FIBER_API int acl_fiber_mutex_trylock(ACL_FIBER_MUTEX* l);

/**
 * �����ɹ���Э�̵��ñ��������н��������ñ�������Э�̱����Ǹ���������������
 * �ڲ����������
 * @param l {ACL_FIBER_MUTEX*} �� acl_fiber_mutex_create ������Э�̻�����
 */
FIBER_API void acl_fiber_mutex_unlock(ACL_FIBER_MUTEX* l);

/**
 * ����Э�̶�д�����̷߳ǰ�ȫ��ֻ������ͬһ�߳���
 * @return {ACL_FIBER_RWLOCK*}
 */
FIBER_API ACL_FIBER_RWLOCK* acl_fiber_rwlock_create(void);

/**
 * �ͷ�Э�̶�д��
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 */
FIBER_API void acl_fiber_rwlock_free(ACL_FIBER_RWLOCK* l);

/**
 * ��Э�̶�д���Ӷ��������������ǰ��������Э�̼��˶�������Э����Ȼ����
 * �����Ӷ��������������ǰ��������Э�̼���д������Э�̽�������״̬��ֱ��
 * д���ͷ�
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 */
FIBER_API void acl_fiber_rwlock_rlock(ACL_FIBER_RWLOCK* l);

/**
 * ��Э�̶�д�������ԼӶ��������������Ƿ�ɹ�������������
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 * @retur {int} ���� 1 ��ʾ�����ɹ������� 0 ��ʾ����ʧ��
 */
FIBER_API int acl_fiber_rwlock_tryrlock(ACL_FIBER_RWLOCK* l);

/**
 * ��Э�̶�д����д����ֻ�е�����δ���κ�Э�̼Ӷ�/д��ʱ�Ż᷵�أ�����������
 * ֱ�������ɼ�д��
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 */
FIBER_API void acl_fiber_rwlock_wlock(ACL_FIBER_RWLOCK* l);

/**
 * ��Э�̶�д�������Լ�д���������Ƿ�����ɹ�������������
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 * @return {int} ���� 1 ��ʾ��д���ɹ������� 0 ��ʾ����ʧ��
 */
FIBER_API int acl_fiber_rwlock_trywlock(ACL_FIBER_RWLOCK* l);

/**
 * ��Э�̶�д���ɹ��Ӷ�����Э�̵��ñ�����������������߱�����֮ǰ�ѳɹ��Ӷ�
 * ���ɹ���Э��
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 */
FIBER_API void acl_fiber_rwlock_runlock(ACL_FIBER_RWLOCK* l);
/**
 * ��Э�̶�д���ɹ���д����Э�̵��ñ�������д���������߱�����֮ǰ�ѳɹ���д
 * ���ɹ���Э��
 * @param l {ACL_FIBER_RWLOCK*} �� acl_fiber_rwlock_create �����Ķ�д��
 */
FIBER_API void acl_fiber_rwlock_wunlock(ACL_FIBER_RWLOCK* l);

#ifdef __cplusplus
}
#endif

#endif
