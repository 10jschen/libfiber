/**
 * Copyright (C) 2015-2018
 * All rights reserved.
 *
 * AUTHOR(S)
 *   Zheng Shuxin
 *   E-mail: shuxin.zheng@qq.com
 * 
 * VERSION
 *   Tue 27 Feb 2018 09:14:19 PM CST
 */

#ifndef FIBER_CHANNEL_INCLUDE_H
#define FIBER_CHANNEL_INCLUDE_H

#include "fiber_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/* channel communication */

/**
 * Э�̼�ͨ�ŵĹܵ�
 */
typedef struct ACL_CHANNEL ACL_CHANNEL;

/**
 * ����Э��ͨ�Źܵ�
 * @param elemsize {int} �� ACL_CHANNEL ���д���Ķ���Ĺ̶��ߴ��С���ֽڣ�
 * @param bufsize {int} ACL_CHANNEL �ڲ���������С�������Ի��� elemsize �ߴ��С
 *  ����ĸ���
 * @return {CHANNNEL*}
 */
FIBER_API ACL_CHANNEL* acl_channel_create(int elemsize, int bufsize);

/**
 * �ͷ��� acl_channel_create ������Э��ͨ�Źܵ�����
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 */
FIBER_API void acl_channel_free(ACL_CHANNEL* c);

/**
 * ����ʽ��ָ�� ACL_CHANNEL �з���ָ���Ķ����ַ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} �����͵Ķ����ַ
 * @return {int} ����ֵ >= 0
 */
FIBER_API int acl_channel_send(ACL_CHANNEL* c, void* v);

/**
 * ������ʽ��ָ�� ACL_CHANNEL �з���ָ���Ķ����ڲ������ acl_channel_create ��ָ��
 * �� elemsize �����С�������ݿ���
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} �����͵Ķ����ַ
 */
FIBER_API int acl_channel_send_nb(ACL_CHANNEL* c, void* v);

/**
 * ��ָ���� ACL_CHANNEL ������ʽ��ȡ����
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} ��Ž������
 * @return {int} ����ֵ >= 0 ��ʾ�ɹ���������
 */
FIBER_API int acl_channel_recv(ACL_CHANNEL* c, void* v);

/**
 * ��ָ���� ACL_CHANNEL �з�����ʽ��ȡ���������Ƿ�������ݶ�����������
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} ��Ž������
 * @return {int} ����ֵ >= 0 ��ʾ�ɹ��������ݣ������ʾδ��������
 */
FIBER_API int acl_channel_recv_nb(ACL_CHANNEL* c, void* v);

/**
 * ��ָ���� ACL_CHANNEL ������ʽ����ָ������ĵ�ַ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} �����Ͷ���ĵ�ַ
 * @return {int} ����ֵ >= 0
 */
FIBER_API int acl_channel_sendp(ACL_CHANNEL* c, void* v);

/**
 * ��ָ���� CHANNLE ������ʽ������ acl_channel_sendp ���͵Ķ���ĵ�ַ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @return {void*} ���ط� NULL��ָ�����յ��Ķ���ĵ�ַ
 */
FIBER_API void *acl_channel_recvp(ACL_CHANNEL* c);

/**
 * ��ָ���� ACL_CHANNEL �з�����ʽ����ָ������ĵ�ַ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param v {void*} �����Ͷ���ĵ�ַ
 * @return {int} ����ֵ >= 0
 */
FIBER_API int acl_channel_sendp_nb(ACL_CHANNEL* c, void* v);

/**
 * ��ָ���� CHANNLE ������ʽ������ acl_channel_sendp ���͵Ķ���ĵ�ַ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @return {void*} ���ط� NULL��ָ�����յ��Ķ���ĵ�ַ��������� NULL ��ʾ
 *  û�ж����κζ���
 */
FIBER_API void *acl_channel_recvp_nb(ACL_CHANNEL* c);

/**
 * ��ָ���� ACL_CHANNEL �з����޷��ų�������ֵ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param val {unsigned long} Ҫ���͵���ֵ
 * @return {int} ����ֵ >= 0
 */
FIBER_API int acl_channel_sendul(ACL_CHANNEL* c, unsigned long val);

/**
 * ��ָ���� ACL_CHANNEL �н����޷��ų�������ֵ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @return {unsigned long}
 */
FIBER_API unsigned long acl_channel_recvul(ACL_CHANNEL* c);

/**
 * ��ָ���� ACL_CHANNEL ���Է�������ʽ�����޷��ų�������ֵ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @param val {unsigned long} Ҫ���͵���ֵ
 * @return {int} ����ֵ >= 0
 */
FIBER_API int acl_channel_sendul_nb(ACL_CHANNEL* c, unsigned long val);

/**
 * ��ָ���� ACL_CHANNEL ���Է�������ʽ�����޷��ų�������ֵ
 * @param c {ACL_CHANNEL*} �� acl_channel_create �����Ĺܵ�����
 * @return {unsigned long}
 */
FIBER_API unsigned long acl_channel_recvul_nb(ACL_CHANNEL* c);

#ifdef __cplusplus
}
#endif

#endif
