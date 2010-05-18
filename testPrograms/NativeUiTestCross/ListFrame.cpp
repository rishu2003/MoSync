/* Copyright (C) 2010 MoSync AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

/*
 * ListFrame.cpp
 *
 *  Created on: May 4, 2010
 *      Author: Romain Chalant
 */

#include "ListFrame.h"

/**
 * Constructor
 */
ListFrame::ListFrame(int id) {
	myid=id;

	MAWidgetParameters wp;
	MAWidgetHandle handle;

	wp.pParent=NULL;
	wp.widgetID=myid;
	//maWinMobileWindow(&wp, &handle);
	//me=handle.pWidget;

	//maAndroidStartActivity(myid);

	//MAWidgetParameters mp;
	//mp.pParent=me;
	//maWinMobileMenuBar(&mp);
	
	maIPhoneView(&wp, &handle);
	me=handle.pWidget;
	
	maAndroidStartListActivity(id);

	/*
	MAWidgetParameters wparamsListItem;
	char *str1="List item";
	wparamsListItem.pParent = mHandle.pWidget;
	wparamsListItem.widgetID = myid;
	strncpy(wparamsListItem.buf, str1, strlen(str1)+1);
	maIPhoneListItem(&wparamsListItem, NULL);
*/
	
	//maIPhoneListView(&wparamsListItem, &handle);
	
}

/**
 * Destructor
 */
ListFrame::~ListFrame() {

}

/**
 * Returns the widget's ID
 *
 * @return ID of the widget
 */
int ListFrame::getId() {
	Widget::getId();
}

/**
 * Returns the widget's instance INSIDE the runtime
 * (Used for Windows mobile).
 * You normally do not want to call it yourself !
 *
 * @return	Pointer to the widget instance inside the runtime:
 * 			This is dangerous !
 */
void *ListFrame::getInstance() {
	Widget::getInstance();
}

/**
 * Processes events sent by the Manager.
 * Called by the Manager. You should not call it yourself.
 *
 * @param	MAEvent to be processed
 */
void ListFrame::processEvent(const MAEvent &e) {
	if(e.hi_wparam==0) {
		actionListener->onCreate(e.lo_wparam);
	}
	else {
		actionListener->onItemSelected(e.lo_wparam, e.hi_wparam);
	}
}

/**
 * Adds an item to the list
 *
 * @param str	Text to be displayed
 */
void ListFrame::add(char *str) {
	MAWidgetParameters wparamsListItem;
	wparamsListItem.pParent = me;
	wparamsListItem.widgetID = myid;
	strncpy(wparamsListItem.buf, str, strlen(str)+1);
	maIPhoneListItem(&wparamsListItem, NULL);
	maAndroidAddListItem(myid, str);
}

/**
 * Shows the list box window.
 *
 * 
 */
void ListFrame::show() {
	MAWidgetParameters wparamsListView;
	wparamsListView.pParent = me;
	maIPhoneListView(&wparamsListView, NULL);
}



