// Copyright (C) 2009-2012 Gaz Davidson
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp/nirtcpp.hpp

#ifndef NIRT_C_TAR_READER_H_INCLUDED
#define NIRT_C_TAR_READER_H_INCLUDED

#include <nirtcpp/IrrCompileConfig.hpp>

#ifdef __NIRT_COMPILE_WITH_TAR_ARCHIVE_LOADER_

#include <nirtcpp/IReferenceCounted.hpp>
#include <nirtcpp/IReadFile.hpp>
#include <nirtcpp/irrArray.hpp>
#include <nirtcpp/irrString.hpp>
#include <nirtcpp/IFileSystem.hpp>
#include "CFileList.hpp"

namespace nirt
{
namespace io
{

	enum E_TAR_LINK_INDICATOR
	{
		ETLI_REGULAR_FILE_OLD      =  0 ,
		ETLI_REGULAR_FILE          = '0',
		ETLI_LINK_TO_ARCHIVED_FILE = '1', // Hard link
		ETLI_SYMBOLIC_LINK         = '2',
		ETLI_CHAR_SPECIAL_DEVICE   = '3',
		ETLI_BLOCK_SPECIAL_DEVICE  = '4',
		ETLI_DIRECTORY             = '5',
		ETLI_FIFO_SPECIAL_FILE     = '6',
		ETLI_CONTIGUOUS_FILE       = '7'
	};

// byte-align structures
#include <nirtcpp/irrpack.hpp>

	struct STarHeader
	{
		c8 FileName[100];
		c8 FileMode[8];
		c8 UserID[8];
		c8 GroupID[8];
		c8 Size[12];
		c8 ModifiedTime[12];
		c8 Checksum[8];
		c8 Link;
		c8 LinkName[100];
		c8 Magic[6];
		c8 USTARVersion[2];
		c8 UserName[32];
		c8 GroupName[32];
		c8 DeviceMajor[8];
		c8 DeviceMinor[8];
		c8 FileNamePrefix[155];
	} PACK_STRUCT;

// Default alignment
#include <nirtcpp/irrunpack.hpp>

	//! Archiveloader capable of loading ZIP Archives
	class CArchiveLoaderTAR : public IArchiveLoader
	{
	public:

		//! Constructor
		CArchiveLoaderTAR(io::IFileSystem* fs);

		//! returns true if the file maybe is able to be loaded by this class
		//! based on the file extension (e.g. ".tar")
		virtual bool isALoadableFileFormat(const io::path& filename) const override;

		//! Check if the file might be loaded by this class
		/** Check might look into the file.
		\param file File handle to check.
		\return True if file seems to be loadable. */
		virtual bool isALoadableFileFormat(io::IReadFile* file) const override;

		//! Check to see if the loader can create archives of this type.
		/** Check based on the archive type.
		\param fileType The archive type to check.
		\return True if the archile loader supports this type, false if not */
		virtual bool isALoadableFileFormat(E_FILE_ARCHIVE_TYPE fileType) const override;

		//! Creates an archive from the filename
		/** \param file File handle to check.
		\return Pointer to newly created archive, or 0 upon error. */
		virtual IFileArchive* createArchive(const io::path& filename, bool ignoreCase, bool ignorePaths) const override;

		//! creates/loads an archive from the file.
		//! \return Pointer to the created archive. Returns 0 if loading failed.
		virtual io::IFileArchive* createArchive(io::IReadFile* file, bool ignoreCase, bool ignorePaths) const override;

	private:
		io::IFileSystem* FileSystem;
	};



	class CTarReader : public virtual IFileArchive, virtual CFileList
	{
	public:

		CTarReader(IReadFile* file, bool ignoreCase, bool ignorePaths);

		virtual ~CTarReader();

		//! opens a file by file name
		virtual IReadFile* createAndOpenFile(const io::path& filename) override;

		//! opens a file by index
		virtual IReadFile* createAndOpenFile(u32 index) override;

		//! returns the list of files
		virtual const IFileList* getFileList() const override;

		//! get the class Type
		virtual E_FILE_ARCHIVE_TYPE getType() const override { return EFAT_TAR; }

		//! return the name (id) of the file Archive
		virtual const io::path& getArchiveName() const  override {return Path;}

	private:

		u32 populateFileList();

		IReadFile* File;
	};

} // end namespace io
} // end namespace nirt

#endif // __NIRT_COMPILE_WITH_TAR_ARCHIVE_LOADER_
#endif // NIRT_C_TAR_READER_H_INCLUDED
