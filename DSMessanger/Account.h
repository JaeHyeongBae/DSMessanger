#pragma once
using namespace System::Drawing;
using namespace System;
namespace DSMessanger {
	public ref class Account
	{
	public:
		Account(){}
		~Account(){}

		int GetSortIndex()
		{
			return id;
		}

	private:
		int id;
		String^ name = L"N/A";
		Bitmap^ profile_image;
		Image^ background_image;
		int chatroom_id;
	};
}
