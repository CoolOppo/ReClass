#pragma once
#include "ReClass.h"
#if 0
class ReclassSDK
{
public:

	virtual void Test( )
	{
		MessageBox( 0, "Plugin Loaded Successfully", "ReclassSDK", 0 );
	};

	virtual void GetCurrentFilePath( PCHAR szPath )
	{
		if ( theApp.CurrentFilePath.GetLength( ) > 0 )
			strcpy( szPath, theApp.CurrentFilePath.GetBuffer( ) );
	};

	virtual int GetClassCount( )
	{
		return theApp.Classes.size( );
	};

	virtual int GetNodeCount( unsigned int classId )
	{
		if ( classId < theApp.Classes.size( ) )
		{
			CNodeBase* pBase = theApp.Classes.at( classId );

			if ( pBase )
				return pBase->Nodes.size( );
		}

		return -1;
	};

	virtual int CreateClass( PCHAR szName )
	{
		// Try to find class
		int id = FindClassByName( szName );

		// Class already exists
		if ( id != -1 )
			return -1;

		// Create Class
		CNodeClass* pClass = new CNodeClass;
		pClass->Name = szName;
		theApp.Classes.push_back( pClass );

		// Open GUI Child Frame
		CMainFrame*  pFrame = static_cast<CMainFrame*>( AfxGetApp( )->m_pMainWnd );

		CChildFrame* pChild = ( CChildFrame* )pFrame->CreateNewChild(	RUNTIME_CLASS( CChildFrame ),
																		IDR_ReClass2011TYPE,
																		theApp.m_hMDIMenu, theApp.m_hMDIAccel );
		pChild->m_wndView.m_pClass = pClass;
	
		// Terrible; Fix this later
		return theApp.Classes.size( ) - 1;
		
		//FindClassByName( szName );
		//FindClassByName( szName );
		// theApp.Classes.back( )
		//
	}

	virtual int FindClassByName( PCHAR szName )
	{
		unsigned int id = 0;

		while( ++id < theApp.Classes.size( ) )
			if( strcmp( theApp.Classes.at( id )->Name, szName ) == 0 )
				return id;

		return -1;
	};

	virtual bool AddNode( int classId, NodeType type, PCHAR szName )
	{
		CNodeBase* pBase = FindPointerByClassId( classId );

		if ( !pBase )
		{
			printf( "[!] Cannot find class\n" );
			return false;
		};

		if ( type != nt_vtable && type != nt_pointer )
		{
			CNodeBase* pNode = theApp.CreateNewNode( type );
			// CNodeHex64* pNode = new CNodeHex64;
			pNode->pParent = pBase;
			pNode->Name = szName;

			pBase->Nodes.push_back( pNode );
		}


	};

	__int16 major_version;
	__int16 minor_version;

	static ReclassSDK* m_pReclassSDK;

	static ReclassSDK* GetInstance( )
	{
		if ( m_pReclassSDK == NULL )
			 m_pReclassSDK = new ReclassSDK( );

		return m_pReclassSDK;
	};

private:
	int FindClassIdByPointer( CNodeBase* pBase )
	{
		unsigned int id = 0;

		while( ++id < theApp.Classes.size( ) )
			if( theApp.Classes.at( id )->pParent == pBase )
				return id;

		return -1;
	};

	CNodeBase* FindPointerByClassId( size_t Id )
	{
		if ( Id < theApp.Classes.size( ) )
			return theApp.Classes.at( Id );

		return NULL;
	};
};

void LoadPlugin( LPCSTR pszPath )
{
	printf( "Reclass SDK: %I64X\n", ReclassSDK::GetInstance( ) );

	ReclassSDK::GetInstance( )->major_version = 1;
	ReclassSDK::GetInstance( )->minor_version = 1;

	HMODULE hPlugin = LoadLibrary( pszPath );

	printf( "[?] Loaded plugin: %I64X\n", hPlugin );

	if ( !hPlugin )
	{
		printf( "[!] GetLastError( ) = %d\n", GetLastError( ) );
	}

	FARPROC pInit = GetProcAddress( hPlugin, "Init" );
	printf( "[?] Init function = %I64X\n", pInit );

	if ( pInit )
	{
		typedef void ( __cdecl* tInit )( ReclassSDK* pReclassSDK );
		tInit oInit = ( tInit )pInit;
		oInit( ReclassSDK::GetInstance( ) );
	}
}
#endif