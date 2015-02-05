/******************************************************************
*
*	CyberLink for C
*
*	Copyright (C) Satoshi Konno 2005
*
*       Copyright (C) 2006 Nokia Corporation. All rights reserved.
*
*       This is licensed under BSD-style license,
*       see file COPYING.
*
*	File: cproperty.h
*
*	Revision:
*
*	06/21/05
*		- first revision
*
******************************************************************/

#ifndef _CG_UPNP_CPROPERTY_H_
#define _CG_UPNP_CPROPERTY_H_

#include <mupnp/typedef.h>

#include <mupnp/util/list.h>
#include <mupnp/util/string.h>
#include <mupnp/net/url.h>

#include <mupnp/statevariable.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * Type definition for UPnP property
 */
typedef struct _mUpnpUpnpProperty {
	BOOL headFlag;
	struct _mUpnpUpnpProperty *prev;
	struct _mUpnpUpnpProperty *next;

	mUpnpString *name;
	mUpnpString *value;
	mUpnpString *sid;
	size_t seq;
} mUpnpUpnpProperty, mUpnpUpnpPropertyList;

/****************************************
* Function (Property)
****************************************/

/**
 * Construct new UPnP property object
 */
mUpnpUpnpProperty *mupnp_upnp_property_new();

/**
 * Delete UPnP property object
 *
 * @param prop UPnP property
 */
void mupnp_upnp_property_delete(mUpnpUpnpProperty *prop);

/**
 * Clear UPnP property
 *
 * @param prop UPnP property
 */
void mupnp_upnp_property_clear(mUpnpUpnpProperty *prop);

/**
 * Fetches next UPnP property from property list
 *
 * @param prop UPnP property
 */
#define mupnp_upnp_property_next(prop) (mUpnpUpnpProperty *)mupnp_list_next((mUpnpList *)prop)

/**** name ****/
/**
 * Set property name
 *
 * @param prop UPnP property
 * @param value Name
 */
#define mupnp_upnp_property_setname(prop, value) mupnp_string_setvalue(prop->name, value)

/**
 * Get property name
 *
 * @param prop UPnP property
 */
#define mupnp_upnp_property_getname(prop) mupnp_string_getvalue(prop->name)

/**** value ****/

/**
 * Set value for UPnP property
 *
 * @param prop UPnP property
 * @param nvalue Value
 */
#define mupnp_upnp_property_setvalue(prop, nvalue) mupnp_string_setvalue(prop->value, nvalue)

/**
 * Get value from property
 *
 * @param prop UPnP property
 */
#define mupnp_upnp_property_getvalue(prop) mupnp_string_getvalue(prop->value)

/**** sid ****/

/**
 * Set SID for UPnP property
 *
 * @param prop UPnP property
 * @param value Value
 */
#define mupnp_upnp_property_setsid(prop, value) mupnp_string_setvalue(prop->sid, value)

/**
 * Get SID from UPnP property
 *
 * @param prop UPnP property
 */
#define mupnp_upnp_property_getsid(prop) mupnp_string_getvalue(prop->sid)

/**** seq ****/

/**
 * Set sequence number for UPnP property
 *
 * @param prop UPnP property
 * @param value
 */
#define mupnp_upnp_property_setseq(prop, value) (prop->seq = value)

/**
 * Get sequence number from UPnP property
 *
 * @param prop UPnP property
 */
#define mupnp_upnp_property_getseq(prop) (prop->seq)

/****************************************
* Function (PropertyList)
****************************************/

/**
 * Create new UPnP property list
 */
mUpnpUpnpPropertyList *mupnp_upnp_propertylist_new();

/**
 * Delete UPnP property list
 *
 * @param propertylist UPnP property list
 */
void mupnp_upnp_propertylist_delete(mUpnpUpnpPropertyList *propertylist);

/**
 * Clear UPnP propertylist
 *
 * @param propList UPnP property list
 */
#define mupnp_upnp_propertylist_clear(propList) mupnp_list_clear((mUpnpList *)propList, (CG_LIST_DESTRUCTORFUNC)mupnp_upnp_property_delete)

/**
 * Get size of property list
 *
 * @param propList UPnP property list
 */
#define mupnp_upnp_propertylist_size(propList) mupnp_list_size((mUpnpList *)propList)

/**
 * Get next list element from property list
 *
 * @param propList UPnP property list
 */
#define mupnp_upnp_propertylist_gets(propList) (mUpnpUpnpProperty *)mupnp_list_next((mUpnpList *)propList)

/**
 * Add new property into property list
 *
 * @param propList UPnP property list
 * @param prop UPnP property
 */
#define mupnp_upnp_propertylist_add(propList, prop) mupnp_list_add((mUpnpList *)propList, (mUpnpList *)prop)

#ifdef  __cplusplus
}
#endif

#endif
