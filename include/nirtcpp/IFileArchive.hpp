// Copyright (C) 2002-2012 Nikolaus Gebhardt/ Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_I_FILE_ARCHIVE_H_INCLUDED
#define NIRT_I_FILE_ARCHIVE_H_INCLUDED

#include <nirtcpp/IReadFile.hpp>
#include <nirtcpp/IFileList.hpp>

namespace nirt
{

namespace io
{

//! FileSystemType: which filesystem should be used for e.g. browsing
enum EFileSystemType
{
	FILESYSTEM_NATIVE = 0,	// Native OS FileSystem
	FILESYSTEM_VIRTUAL	// Virtual FileSystem
};

//! Contains the different types of archives
enum E_FILE_ARCHIVE_TYPE
{
	//! A PKZIP archive
	EFAT_ZIP     = MAKE_NIRT_ID('Z','I','P', 0),

	//! A gzip archive
	EFAT_GZIP    = MAKE_NIRT_ID('g','z','i','p'),

	//! A virtual directory
	EFAT_FOLDER  = MAKE_NIRT_ID('f','l','d','r'),

	//! An ID Software PAK archive
	EFAT_PAK     = MAKE_NIRT_ID('P','A','K', 0),

	//! A Nebula Device archive
	EFAT_NPK     = MAKE_NIRT_ID('N','P','K', 0),

	//! A Tape ARchive
	EFAT_TAR     = MAKE_NIRT_ID('T','A','R', 0),

	//! A wad Archive, Quake2, Halflife
	EFAT_WAD     = MAKE_NIRT_ID('W','A','D', 0),

	//! The type of this archive is unknown
	EFAT_UNKNOWN = MAKE_NIRT_ID('u','n','k','n')
};

//! The FileArchive manages archives and provides access to files inside them.
class IFileArchive : public virtual IReferenceCounted
{
public:

	//! Opens a file based on its name
	/** Creates and returns a new IReadFile for a file in the archive.
	\param filename The file to open
	\return Returns A pointer to the created file on success,
	or 0 on failure. */
	virtual IReadFile* createAndOpenFile(const path& filename) =0;

	//! Opens a file based on its position in the file list.
	/** Creates and returns
	\param index The zero based index of the file.
	\return Returns a pointer to the created file on success, or 0 on failure. */
	virtual IReadFile* createAndOpenFile(u32 index) =0;

	//! Returns the complete file tree
	/** \return Returns the complete directory tree for the archive,
	including all files and folders */
	virtual const IFileList* getFileList() const =0;

	//! get the archive type
	virtual E_FILE_ARCHIVE_TYPE getType() const { return EFAT_UNKNOWN; }

	//! return the name (id) of the file Archive
	virtual const io::path& getArchiveName() const =0;

	//! An optionally used password string
	/** This variable is publicly accessible from the interface in order to
	avoid single access patterns to this place, and hence allow some more
	obscurity.
	*/
	core::stringc Password;
};

//! Class which is able to create an archive from a file.
/** If you want the Nirtcpp Engine be able to load archives of
currently unsupported file formats (e.g .wad), then implement
this and add your new Archive loader with
IFileSystem::addArchiveLoader() to the engine. */
class IArchiveLoader : public virtual IReferenceCounted
{
public:
	//! Check if the file might be loaded by this class
	/** Check based on the file extension (e.g. ".zip")
	\param filename Name of file to check.
	\return True if file seems to be loadable. */
	virtual bool isALoadableFileFormat(const path& filename) const =0;

	//! Check if the file might be loaded by this class
	/** This check may look into the file.
	\param file File handle to check.
	\return True if file seems to be loadable. */
	virtual bool isALoadableFileFormat(io::IReadFile* file) const =0;

	//! Check to see if the loader can create archives of this type.
	/** Check based on the archive type.
	\param fileType The archive type to check.
	\return True if the archive loader supports this type, false if not */
	virtual bool isALoadableFileFormat(E_FILE_ARCHIVE_TYPE fileType) const =0;

	//! Creates an archive from the filename
	/** \param filename File to use.
	\param ignoreCase Searching is performed without regarding the case
	\param ignorePaths Files are searched for without checking for the directories
	\return Pointer to newly created archive, or 0 upon error. */
	virtual IFileArchive* createArchive(const path& filename, bool ignoreCase, bool ignorePaths) const =0;

	//! Creates an archive from the file
	/** \param file File handle to use.
	\param ignoreCase Searching is performed without regarding the case
	\param ignorePaths Files are searched for without checking for the directories
	\return Pointer to newly created archive, or 0 upon error. */
	virtual IFileArchive* createArchive(io::IReadFile* file, bool ignoreCase, bool ignorePaths) const =0;
};


} // end namespace io
} // end namespace nirt

#endif
