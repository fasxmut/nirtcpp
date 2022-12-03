// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Nirtcpp Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_FILE_SYSTEM_H_INCLUDED
#define NIRT_C_FILE_SYSTEM_H_INCLUDED

#include "IFileSystem.h"
#include "irrArray.h"

namespace nirt
{
namespace io
{

	class CZipReader;
	class CPakReader;
	class CMountPointReader;

/*!
	FileSystem which uses normal files and one zipfile
*/
class CFileSystem : public IFileSystem
{
public:

	//! constructor
	CFileSystem();

	//! destructor
	virtual ~CFileSystem();

	//! opens a file for read access
	virtual IReadFile* createAndOpenFile(const io::path& filename) override;

	//! Creates an IReadFile interface for accessing memory like a file.
	virtual IReadFile* createMemoryReadFile(const void* memory, s32 len, const io::path& fileName, bool deleteMemoryWhenDropped = false) override;

	//! Creates an IReadFile interface for accessing files inside files
	virtual IReadFile* createLimitReadFile(const io::path& fileName, IReadFile* alreadyOpenedFile, long pos, long areaSize) override;

	//! Creates an IWriteFile interface for accessing memory like a file.
	virtual IWriteFile* createMemoryWriteFile(void* memory, s32 len, const io::path& fileName, bool deleteMemoryWhenDropped=false) override;

	//! Opens a file for write access.
	virtual IWriteFile* createAndWriteFile(const io::path& filename, bool append=false) override;

	//! Adds an archive to the file system.
	virtual bool addFileArchive(const io::path& filename,
			bool ignoreCase = true, bool ignorePaths = true,
			E_FILE_ARCHIVE_TYPE archiveType = EFAT_UNKNOWN,
			const core::stringc& password="",
			IFileArchive** retArchive = 0) override;

	//! Adds an archive to the file system.
	virtual bool addFileArchive(IReadFile* file, bool ignoreCase=true,
			bool ignorePaths=true,
			E_FILE_ARCHIVE_TYPE archiveType=EFAT_UNKNOWN,
			const core::stringc& password="",
			IFileArchive** retArchive = 0) override;

	//! Adds an archive to the file system.
	virtual bool addFileArchive(IFileArchive* archive) override;

	//! move the hirarchy of the filesystem. moves sourceIndex relative up or down
	virtual bool moveFileArchive(u32 sourceIndex, s32 relative) override;

	//! Adds an external archive loader to the engine.
	virtual void addArchiveLoader(IArchiveLoader* loader) override;

	//! Returns the total number of archive loaders added.
	virtual u32 getArchiveLoaderCount() const override;

	//! Gets the archive loader by index.
	virtual IArchiveLoader* getArchiveLoader(u32 index) const override;

	//! gets the file archive count
	virtual u32 getFileArchiveCount() const override;

	//! gets an archive
	virtual IFileArchive* getFileArchive(u32 index) override;

	//! removes an archive from the file system.
	virtual bool removeFileArchive(u32 index) override;

	//! removes an archive from the file system.
	virtual bool removeFileArchive(const io::path& filename) override;

	//! Removes an archive from the file system.
	virtual bool removeFileArchive(const IFileArchive* archive) override;

	//! Returns the string of the current working directory
	virtual const io::path& getWorkingDirectory() override;

	//! Changes the current Working Directory to the string given.
	//! The string is operating system dependent. Under Windows it will look
	//! like this: "drive:\directory\sudirectory\"
	virtual bool changeWorkingDirectoryTo(const io::path& newDirectory) override;

	//! Converts a relative path to an absolute (unique) path, resolving symbolic links
	virtual io::path getAbsolutePath(const io::path& filename) const override;

	//! Returns the directory a file is located in.
	/** \param filename: The file to get the directory from */
	virtual io::path getFileDir(const io::path& filename) const override;

	//! Returns the base part of a filename, i.e. the name without the directory
	//! part. If no directory is prefixed, the full name is returned.
	/** \param filename: The file to get the basename from */
	virtual io::path getFileBasename(const io::path& filename, bool keepExtension=true) const override;

	//! flatten a path and file name for example: "/you/me/../." becomes "/you"
	virtual io::path& flattenFilename( io::path& directory, const io::path& root = "/" ) const override;

	//! Get the relative filename, relative to the given directory
	virtual path getRelativeFilename(const path& filename, const path& directory) const override;

	virtual EFileSystemType setFileListSystem(EFileSystemType listType) override;

	//! Creates a list of files and directories in the current working directory
	//! and returns it.
	virtual IFileList* createFileList() override;

	//! Creates an empty filelist
	virtual IFileList* createEmptyFileList(const io::path& path, bool ignoreCase, bool ignorePaths) override;

	//! determines if a file exists and would be able to be opened.
	virtual bool existFile(const io::path& filename) const override;

	//! Creates a XML Reader from a file.
	virtual IXMLReader* createXMLReader(const io::path& filename) override;

	//! Creates a XML Reader from a file.
	virtual IXMLReader* createXMLReader(IReadFile* file) override;

	//! Creates a XML Reader from a file.
	virtual IXMLReaderUTF8* createXMLReaderUTF8(const io::path& filename) override;

	//! Creates a XML Reader from a file.
	virtual IXMLReaderUTF8* createXMLReaderUTF8(IReadFile* file) override;

	//! Creates a XML Writer from a file.
	virtual IXMLWriter* createXMLWriter(const io::path& filename) override;

	//! Creates a XML Writer from a file.
	virtual IXMLWriter* createXMLWriter(IWriteFile* file) override;

	//! Creates a XML Writer from a file which will write ASCII/UTF-8 characters (char*).
	virtual IXMLWriterUTF8* createXMLWriterUTF8(const path& filename) override;

	//! Creates a XML Writer from a file which will write ASCII/UTF-8 characters (char*).
	virtual IXMLWriterUTF8* createXMLWriterUTF8(IWriteFile* file) override;

	//! Creates a new empty collection of attributes, usable for serialization and more.
	virtual IAttributes* createEmptyAttributes(video::IVideoDriver* driver) override;

private:

	// don't expose, needs refactoring
	bool changeArchivePassword(const path& filename,
			const core::stringc& password,
			IFileArchive** archive = 0);

	//! Currently used FileSystemType
	EFileSystemType FileSystemType;
	//! WorkingDirectory for Native and Virtual filesystems
	io::path WorkingDirectory [2];
	//! currently attached ArchiveLoaders
	core::array<IArchiveLoader*> ArchiveLoader;
	//! currently attached Archives
	core::array<IFileArchive*> FileArchives;
};


} // end namespace nirt
} // end namespace io

#endif
