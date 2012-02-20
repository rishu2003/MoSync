/* Copyright (C) 2012 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

package com.mosync.nativeui.ui.widgets;

import android.widget.RadioButton;

import com.mosync.internal.generated.IX_WIDGET;
import com.mosync.nativeui.util.properties.BooleanConverter;
import com.mosync.nativeui.util.properties.ColorConverter;
import com.mosync.nativeui.util.properties.InvalidPropertyValueException;
import com.mosync.nativeui.util.properties.PropertyConversionException;

/**
 * A radio button widget is a two-states button that can be either checked
 * or unchecked.
 * Radio buttons are automatically grouped inside RadioGroup element
 * so that no more than one can be selected at a time.
 * @author emma
 */
public class RadioButtonWidget extends Widget
{
	/**
	 * Constructor.
	 *
	 * @param handle Integer handle corresponding to this instance.
	 * @param radioButton A radioButton wrapped by this widget.
	 */
	public RadioButtonWidget(int handle, RadioButton radioButton)
	{
		super( handle, radioButton );
	}

	@Override
	public boolean setProperty(String property, String value)
			throws PropertyConversionException, InvalidPropertyValueException
	{
		if( super.setProperty(property, value) )
		{
			return true;
		}

		RadioButton radioButton = (RadioButton) getView( );
		if( property.equals( IX_WIDGET.MAW_RADIO_BUTTON_TOGGLE ) )
		{
			radioButton.toggle();
		}
		else if( property.equals( IX_WIDGET.MAW_RADIO_BUTTON_TEXT ) )
		{
			radioButton.setText(value);
		}
		else if( property.equals( IX_WIDGET.MAW_RADIO_BUTTON_TEXT_COLOR ) )
		{
			radioButton.setTextColor( ColorConverter.convert( value ) );
		}
		else
		{
			return false;
		}
		return true;
	}

	/**
	 * @see Widget.getProperty.
	 */
	@Override
	public String getProperty(String property)
	{
		if( property.equals( IX_WIDGET.MAW_RADIO_BUTTON_TEXT ) )
		{
			RadioButton radioButton = (RadioButton) getView( );
			return radioButton.getText().toString();
		}
		else
		{
			return super.getProperty( property );
		}
	}
}
