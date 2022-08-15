/*
	==========================================================================
	Module: AFStrENU.js
	==========================================================================
	JavaScript language dependent strings.
	==========================================================================
	The Software, including this file, is subject to the End User License
	Agreement.
	Copyright (c) 1998, Adobe Systems Incorporated, All Rights Reserved.
	==========================================================================
*/

/* ==== Strings ==== */
/* All of our user strings are defined here. Use Shift-JIS encoding for
** double byte platforms. These strings need to be translated for each language. */
if (app.language == "ENU") {
	IDS_LANGUAGE 		= "ENU";
	IDS_GREATER_THAN	= "Invalid value: must be greater than or equal to %s.";
	IDS_GT_AND_LT		= "Invalid value: must be greater than or equal to %s and less than or equal to %s.";
	IDS_LESS_THAN		= "Invalid value: must be less than or equal to %s.";
	IDS_INVALID_MONTH	= "** Invalid **";
	IDS_INVALID_DATE	= "Invalid date/time: please ensure that the date/time exists and that all 4 digits of any year are supplied";
	IDS_INVALID_VALUE	= "The value entered does not match the format of the field";
	IDS_AM = "am";
	IDS_PM = "pm";

	/* This string contains month info in the following format:
	** month name or abbreviation (left bracket) month number (right bracket)
	** Note that the first string with the given number will be returned by
	** AFGetMonthString (look in AForm.js)
	** Also note that the months and abbreviations should be in order of most
	** to least definitive in case an abbreviation matches part of another
	** month or abbreviation */
	IDS_MONTH_INFO	=	"January[1]" +
						"February[2]" +
						"March[3]" +
						"April[4]" +
						"May[5]" +
						"June[6]" +
						"July[7]" +
						"August[8]" +
						"September[9]" +
						"October[10]" +
						"November[11]" +
						"December[12]" +
						"Sept[9]" +
						"Jan[1]" +
						"Feb[2]" +
						"Mar[3]" +
						"Apr[4]" +
						"Jun[6]" +
						"Jul[7]" +
						"Aug[8]" +
						"Sep[9]" +
						"Oct[10]" +
						"Nov[11]" +
						"Dec[12]";
}