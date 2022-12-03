// Copyright (C) 2008-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in nirtcpp.h

#ifndef NIRT_C_INDEX_BUFFER_H_INCLUDED
#define NIRT_C_INDEX_BUFFER_H_INCLUDED

#include "IIndexBuffer.h"

namespace nirt
{
namespace scene
{

	class CIndexBuffer : public IIndexBuffer
	{
		// Virtual function wrapper around nirt::core::array
		class IIndexList
		{
		public:
			virtual ~IIndexList(){};

			virtual u32 stride() const =0;
			virtual u32 size() const =0;
			virtual void push_back(u32 value) =0;
			virtual u32 operator [](u32 index) const =0;
			virtual u32 getLast() =0;
			virtual void setValue(u32 index, u32 value) =0;
			virtual void set_used(u32 usedNow) =0;
			virtual void reallocate(u32 new_size, bool canShrink=true) =0;
			virtual u32 allocated_size() const =0;
			virtual void* pointer() =0;
			virtual const void* const_pointer() const =0;
			virtual video::E_INDEX_TYPE getType() const =0;
		};

		template <class T>
		class CSpecificIndexList : public IIndexList
		{
		public:
			core::array<T> Indices;

			virtual u32 stride() const override {return sizeof(T);}

			virtual u32 size() const override {return Indices.size();}

			virtual void push_back(u32 value) override
			{
				Indices.push_back((T)value);
			}

			virtual u32 operator [](u32 index) const override
			{
				return (u32)(Indices[index]);
			}

			virtual u32 getLast() override {return (u32)Indices.getLast();}

			virtual void setValue(u32 index, u32 value) override
			{
				Indices[index]=(T)value;
			}

			virtual void set_used(u32 usedNow) override
			{
				Indices.set_used(usedNow);
			}

			virtual void reallocate(u32 new_size, bool canShrink) override
			{
				Indices.reallocate(new_size, canShrink);
			}

			virtual u32 allocated_size() const override
			{
				return Indices.allocated_size();
			}

			virtual void* pointer() override  { return Indices.pointer(); }
			virtual const void* const_pointer() const override  { return Indices.const_pointer(); }

			virtual video::E_INDEX_TYPE getType() const override
			{
				if (sizeof(T)==sizeof(u16))
					return video::EIT_16BIT;
				else
					return video::EIT_32BIT;
			}
		};

	public:
		IIndexList *Indices;

		CIndexBuffer(video::E_INDEX_TYPE IndexType) :Indices(0), MappingHint(EHM_NEVER), ChangedID(1)
		{
			setType(IndexType);
		}

		CIndexBuffer(const IIndexBuffer &IndexBufferCopy) :Indices(0), MappingHint(EHM_NEVER), ChangedID(1)
		{
			setType(IndexBufferCopy.getType());
			reallocate(IndexBufferCopy.size());

			for (u32 n=0;n<IndexBufferCopy.size();++n)
				push_back(IndexBufferCopy[n]);
		}

		virtual ~CIndexBuffer()
		{
			delete Indices;
		}

		virtual void setType(video::E_INDEX_TYPE indexType) override
		{
			if ( Indices && Indices->getType() == indexType )
				return;

			IIndexList *NewIndices=0;

			switch (indexType)
			{
				case video::EIT_16BIT:
				{
					NewIndices=new CSpecificIndexList<u16>;
					break;
				}
				case video::EIT_32BIT:
				{
					NewIndices=new CSpecificIndexList<u32>;
					break;
				}
			}

			if (Indices)
			{
				NewIndices->reallocate( Indices->size() );

				for(u32 n=0;n<Indices->size();++n)
					NewIndices->push_back((*Indices)[n]);

				delete Indices;
			}

			Indices=NewIndices;
		}

		virtual void* getData() override {return Indices->pointer();}
		virtual const void* getData() const override { return Indices->const_pointer(); }

		virtual video::E_INDEX_TYPE getType() const override {return Indices->getType();}

		virtual u32 stride() const override {return Indices->stride();}

		virtual u32 size() const override
		{
			return Indices->size();
		}

		virtual void push_back(u32 value) override
		{
			Indices->push_back(value);
		}

		virtual u32 operator [](u32 index) const override
		{
			return (*Indices)[index];
		}

		virtual u32 getLast() override
		{
			return Indices->getLast();
		}

		virtual void setValue(u32 index, u32 value) override
		{
			Indices->setValue(index, value);
		}

		virtual void set_used(u32 usedNow) override
		{
			Indices->set_used(usedNow);
		}

		virtual void reallocate(u32 new_size, bool canShrink=true) override
		{
			Indices->reallocate(new_size, canShrink);
		}

		virtual u32 allocated_size() const override
		{
			return Indices->allocated_size();
		}

		//! get the current hardware mapping hint
		virtual E_HARDWARE_MAPPING getHardwareMappingHint() const override
		{
			return MappingHint;
		}

		//! set the hardware mapping hint, for driver
		virtual void setHardwareMappingHint( E_HARDWARE_MAPPING NewMappingHint ) override
		{
			MappingHint=NewMappingHint;
		}

		//! flags the mesh as changed, reloads hardware buffers
		virtual void setDirty() override
		{
			++ChangedID;
		}

		//! Get the currently used ID for identification of changes.
		/** This shouldn't be used for anything outside the VideoDriver. */
		virtual u32 getChangedID() const override {return ChangedID;}

		E_HARDWARE_MAPPING MappingHint;
		u32 ChangedID;
	};


} // end namespace scene
} // end namespace nirt

#endif
