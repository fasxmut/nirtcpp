// This file is part of the "Irrlicht Engine".
// written by Reinhard Ostermeier, reinhard@nospam.r-ostermeier.de

#ifndef NIRT_C_GUI_TREE_VIEW_H_INCLUDED
#define NIRT_C_GUI_TREE_VIEW_H_INCLUDED

#include <nirtcpp/IGUITreeView.hpp>
#include <nirtcpp/irrList.hpp>


namespace nirt
{
namespace gui
{
	// forward declarations
	class IGUIFont;
	class IGUIScrollBar;
	class CGUITreeView;

	//! Node for gui tree view
	class CGUITreeViewNode : public IGUITreeViewNode
	{
	friend class CGUITreeView;

	public:
		//! constructor
		CGUITreeViewNode( CGUITreeView* owner, CGUITreeViewNode* parent );

		//! destructor
		~CGUITreeViewNode();

		//! returns the owner (tree view) of this node
		virtual IGUITreeView* getOwner() const override;

		//! Returns the parent node of this node.
		virtual IGUITreeViewNode* getParent() const override;

		//! returns the text of the node
		virtual const wchar_t* getText() const override
		{ return Text.data(); }

		//! sets the text of the node
		virtual void setText( const wchar_t* text ) override;

		//! returns the icon text of the node
		virtual const wchar_t* getIcon() const override
		{ return Icon.data(); }

		//! sets the icon text of the node
		virtual void setIcon( const wchar_t* icon ) override;

		//! returns the image index of the node
		virtual u32 getImageIndex() const override
		{ return ImageIndex; }

		//! sets the image index of the node
		virtual void setImageIndex( u32 imageIndex ) override
		{ ImageIndex = imageIndex; }

		//! returns the image index of the node
		virtual u32 getSelectedImageIndex() const override
		{ return SelectedImageIndex; }

		//! sets the image index of the node
		virtual void setSelectedImageIndex( u32 imageIndex ) override
		{ SelectedImageIndex = imageIndex; }

		//! returns the user data (void*) of this node
		virtual void* getData() const override
		{ return Data; }

		//! sets the user data (void*) of this node
		virtual void setData( void* data ) override
		{ Data = data; }

		//! returns the user data2 (IReferenceCounted) of this node
		virtual IReferenceCounted* getData2() const override
		{ return Data2; }

		//! sets the user data2 (IReferenceCounted) of this node
		virtual void setData2( IReferenceCounted* data ) override
		{
			if( Data2 )
			{
				Data2->drop();
			}
			Data2 = data;
			if( Data2 )
			{
				Data2->grab();
			}
		}

		//! returns the child item count
		virtual u32 getChildCount() const override
		{ return Children.getSize(); }

		//! removes all children (recursive) from this node
		virtual void clearChildren() override;

		//! returns true if this node has child nodes
		virtual bool hasChildren() const override
		{ return !Children.empty(); }

		//! Adds a new node behind the last child node.
		//! \param text text of the new node
		//! \param icon icon text of the new node
		//! \param imageIndex index of the image for the new node (-1 = none)
		//! \param selectedImageIndex index of the selected image for the new node (-1 = same as imageIndex)
		//! \param data user data (void*) of the new node
		//! \param data2 user data2 (IReferenceCounted*) of the new node
		//! \return
		//! returns the new node
		virtual IGUITreeViewNode* addChildBack(
				const wchar_t* text,
				const wchar_t* icon = 0,
				s32 imageIndex = -1,
				s32 selectedImageIndex = -1,
				void* data = 0,
				IReferenceCounted* data2 = 0) override;

		//! Adds a new node before the first child node.
		//! \param text text of the new node
		//! \param icon icon text of the new node
		//! \param imageIndex index of the image for the new node (-1 = none)
		//! \param selectedImageIndex index of the selected image for the new node (-1 = same as imageIndex)
		//! \param data user data (void*) of the new node
		//! \param data2 user data2 (IReferenceCounted*) of the new node
		//! \return
		//! returns the new node
		virtual IGUITreeViewNode* addChildFront(
				const wchar_t*		text,
				const wchar_t*		icon = 0,
				s32					imageIndex = -1,
				s32					selectedImageIndex = -1,
				void*					data = 0,
				IReferenceCounted*			data2 = 0 ) override;

		//! Adds a new node behind the other node.
		//! The other node has also te be a child node from this node.
		//! \param text text of the new node
		//! \param icon icon text of the new node
		//! \param imageIndex index of the image for the new node (-1 = none)
		//! \param selectedImageIndex index of the selected image for the new node (-1 = same as imageIndex)
		//! \param data user data (void*) of the new node
		//! \param data2 user data2 (IReferenceCounted*) of the new node
		//! \return
		//! returns the new node or 0 if other is no child node from this
		virtual IGUITreeViewNode* insertChildAfter(
				IGUITreeViewNode*	other,
				const wchar_t*		text,
				const wchar_t*		icon = 0,
				s32					imageIndex = -1,
				s32					selectedImageIndex = -1,
				void*					data = 0,
				IReferenceCounted*			data2 = 0 ) override;

		//! Adds a new node before the other node.
		//! The other node has also te be a child node from this node.
		//! \param text text of the new node
		//! \param icon icon text of the new node
		//! \param imageIndex index of the image for the new node (-1 = none)
		//! \param selectedImageIndex index of the selected image for the new node (-1 = same as imageIndex)
		//! \param data user data (void*) of the new node
		//! \param data2 user data2 (IReferenceCounted*) of the new node
		//! \return
		//! returns the new node or 0 if other is no child node from this
		virtual IGUITreeViewNode* insertChildBefore(
				IGUITreeViewNode*	other,
				const wchar_t*		text,
				const wchar_t*		icon = 0,
				s32					imageIndex = -1,
				s32					selectedImageIndex = -1,
				void*					data = 0,
				IReferenceCounted*			data2 = 0 ) override;

		//! Return the first child note from this node.
		virtual IGUITreeViewNode* getFirstChild() const override;

		//! Return the last child note from this node.
		virtual IGUITreeViewNode* getLastChild() const override;

		//! Returns the preverse sibling node from this node.
		virtual IGUITreeViewNode* getPrevSibling() const override;

		//! Returns the next sibling node from this node.
		virtual IGUITreeViewNode* getNextSibling() const override;

		//! Returns the next visible (expanded, may be out of scrolling) node from this node.
		virtual IGUITreeViewNode* getNextVisible() const override;

		//! Deletes a child node.
		virtual bool deleteChild( IGUITreeViewNode* child ) override;

		//! Moves a child node one position up.
		virtual bool moveChildUp( IGUITreeViewNode* child ) override;

		//! Moves a child node one position down.
		virtual bool moveChildDown( IGUITreeViewNode* child ) override;

		//! Returns true if the node is expanded (children are visible).
		virtual bool getExpanded() const override
		{ return Expanded; }

		//! Sets if the node is expanded.
		virtual void setExpanded( bool expanded ) override;

		//! Returns true if the node is currently selected.
		virtual bool getSelected() const override;

		//! Sets this node as selected.
		virtual void setSelected( bool selected ) override;

		//! Returns true if this node is the root node.
		virtual bool isRoot() const override;

		//! Returns the level of this node.
		virtual s32 getLevel() const override;

		//! Returns true if this node is visible (all parents are expanded).
		virtual bool isVisible() const override;

	private:

		CGUITreeView*			Owner;
		CGUITreeViewNode*		Parent;
		core::stringw			Text;
		core::stringw			Icon;
		s32				ImageIndex;
		s32				SelectedImageIndex;
		void*				Data;
		IReferenceCounted*		Data2;
		bool				Expanded;
		core::list<CGUITreeViewNode*>	Children;
	};


	//! Default tree view GUI element.
	class CGUITreeView : public IGUITreeView
	{
	friend class CGUITreeViewNode;

	public:
		//! constructor
		CGUITreeView( IGUIEnvironment* environment, IGUIElement* parent,
			s32 id, core::rect<s32> rectangle, bool clip = true,
			bool drawBack = false, bool scrollBarVertical = true, bool scrollBarHorizontal = true );

		//! destructor
		virtual ~CGUITreeView();

		//! returns the root node (not visible) from the tree.
		virtual IGUITreeViewNode* getRoot() const override
		{ return Root; }

		//! returns the selected node of the tree or 0 if none is selected
		virtual IGUITreeViewNode* getSelected() const override
		{ return Selected; }

		//! returns true if the tree lines are visible
		virtual bool getLinesVisible() const override
		{ return LinesVisible; }

		//! sets if the tree lines are visible
		virtual void setLinesVisible( bool visible ) override
		{ LinesVisible = visible; }

		//! called if an event happened.
		virtual bool OnEvent( const SEvent &event ) override;

		//! draws the element and its children
		virtual void draw() override;

		//! Sets the font which should be used as icon font. This font is set to the Nirtcpp engine
		//! built-in-font by default. Icons can be displayed in front of every list item.
		//! An icon is a string, displayed with the icon font. When using the build-in-font of the
		//! Nirtcpp engine as icon font, the icon strings defined in GUIIcons.h can be used.
		virtual void setIconFont( IGUIFont* font ) override;

		//! Sets a skin independent font.
		/** \param font: New font to set or 0 to use the skin-font. */
		virtual void setOverrideFont(IGUIFont* font=0) override;

		//! Gets the override font (if any)
		/** \return The override font (may be 0) */
		virtual IGUIFont* getOverrideFont(void) const override;

		//! Get the font which is used for drawing
		/** This is the override font when one is set and the
		font of the skin otherwise. */
		virtual IGUIFont* getActiveFont() const override;

		//! Sets the image list which should be used for the image and selected image of every node.
		//! The default is 0 (no images).
		virtual void setImageList( IGUIImageList* imageList ) override;

		//! Returns the image list which is used for the nodes.
		virtual IGUIImageList* getImageList() const override
		{ return ImageList; }

		//! Sets if the image is left of the icon. Default is true.
		virtual void setImageLeftOfIcon( bool bLeftOf ) override
		{ ImageLeftOfIcon = bLeftOf; }

		//! Returns if the Image is left of the icon. Default is true.
		virtual bool getImageLeftOfIcon() const override
		{ return ImageLeftOfIcon; }

		//! Returns the node which is associated to the last event.
		virtual IGUITreeViewNode* getLastEventNode() const override
		{ return LastEventNode; }

		//! Access the vertical scrollbar
		virtual IGUIScrollBar* getVerticalScrollBar() const override;

		//! Access the horizontal scrollbar
		virtual IGUIScrollBar* getHorizontalScrollBar() const override;

	private:
		//! calculates the heigth of an node and of all visible nodes.
		void recalculateItemHeight();

		//! Resize scrollbars when their size in the skin has changed
		void updateScrollBarSize(s32 size);

		//! executes an mouse action (like selectNew of CGUIListBox)
		void mouseAction( s32 xpos, s32 ypos, bool onlyHover = false );

		CGUITreeViewNode*	Root;
		IGUITreeViewNode*	Selected;
		s32			ItemHeight;
		s32			IndentWidth;
		s32			TotalItemHeight;
		s32			TotalItemWidth;
		s32			ScrollBarSize;
		IGUIFont*		Font;
		gui::IGUIFont*	OverrideFont;
		IGUIFont*		IconFont;
		IGUIScrollBar*		ScrollBarH;
		IGUIScrollBar*		ScrollBarV;
		IGUIImageList*		ImageList;
		IGUITreeViewNode*	LastEventNode;
		bool			LinesVisible;
		bool			Selecting;
		bool			Clip;
		bool			DrawBack;
		bool			ImageLeftOfIcon;
	};


} // end namespace gui
} // end namespace nirt

#endif
