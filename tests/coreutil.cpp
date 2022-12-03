#include "testUtils.h"

using namespace nirt;
using namespace core;

bool testMergeFilename()
{
	// path mergeFilename(const path& path, const path& filename, const path& extension = "");
	if ( mergeFilename(NIRT_TEXT(""), NIRT_TEXT(""), NIRT_TEXT("") ) != io::path(NIRT_TEXT("")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT(""), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder/")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder/"), NIRT_TEXT(""), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder/")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT("file"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder/file")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder/"), NIRT_TEXT("file"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder/file")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder\\"), NIRT_TEXT("file"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder\\file")) )
		return false;
	if ( mergeFilename(NIRT_TEXT(""), NIRT_TEXT("file"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("file")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("."), NIRT_TEXT("file"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("./file")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT(""), NIRT_TEXT(".bmp") ) != io::path(NIRT_TEXT("folder/.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder/"), NIRT_TEXT(""), NIRT_TEXT(".bmp") ) != io::path(NIRT_TEXT("folder/.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT(""), NIRT_TEXT("bmp") ) != io::path(NIRT_TEXT("folder/.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("."), NIRT_TEXT(""), NIRT_TEXT("bmp") ) != io::path(NIRT_TEXT("./.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT("file"), NIRT_TEXT("bmp") ) != io::path(NIRT_TEXT("folder/file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder/"), NIRT_TEXT("file"), NIRT_TEXT("bmp") ) != io::path(NIRT_TEXT("folder/file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder/"), NIRT_TEXT("file"), NIRT_TEXT(".bmp") ) != io::path(NIRT_TEXT("folder/file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("folder"), NIRT_TEXT("file.bmp"), NIRT_TEXT("") ) != io::path(NIRT_TEXT("folder/file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT(""), NIRT_TEXT("file"), NIRT_TEXT("bmp") ) != io::path(NIRT_TEXT("file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT(""), NIRT_TEXT("file"), NIRT_TEXT(".bmp") ) != io::path(NIRT_TEXT("file.bmp")) )
		return false;
	if ( mergeFilename(NIRT_TEXT("c:"), NIRT_TEXT("file"), NIRT_TEXT(".bmp") ) != io::path(NIRT_TEXT("c:/file.bmp")) ) // TODO: is this actually correct on windows?
		return false; 
	
	return true;
}

// Test the functionality of the Nirtcpp timer
bool testCoreutil(void)
{
	bool ok = true;
	
	ok &= testMergeFilename();
	
	return ok;
}
