#pragma once

namespace Linphone
{
	namespace Core
	{
		/// <summary>
		/// Object that represents a SIP address.
		/// It's an opaque object that represents a SIP address, i.e. the content of SIP's "from" and "to" headers.
		/// A SIP address is made of a display name, username, domain, port and various URI headers(such as tags).
		/// It looks like "Alice &lt;sip:alice@example.net&gt;". The LinphoneAddress has methods to extract and manipulate all parts of the address.
		/// When some part of the address (for example the username) is empty, the accessor method return null.
		/// </summary>
		/// <example>
		/// Can be instancied using
		/// <code>
		/// LinphoneAddress addr = LinphoneCoreFactory.CreateLinphoneAddress("sip:alice@example.net");
		/// </code>
		/// or
		/// <code>
		/// LinphoneAddress addr = LinphoneCoreFactory.CreateLinphoneAddress("alice", "example.net", "Alice B.");
		/// </code>
		/// </example>
		public ref class LinphoneAddress sealed
		{
		public:
			/// <summary>
			/// Human display name
			/// </summary>
			/// <returns>
			/// null if not set
			/// </returns>
			Platform::String^ GetDisplayName();

			/// <returns>
			/// null if not set
			/// </returns>
			Platform::String^ GetUserName();

			/// <returns>
			/// null if not set
			/// </returns>
			Platform::String^ GetDomain();

			int GetPort();

			void SetDisplayName(Platform::String^ name);
			void SetUserName(Platform::String^ username);
			void SetDomain(Platform::String^ domain);
			void SetPort(int port);

			void Clean();

			/// <returns>
			/// the address as a string
			/// </returns>
			Platform::String^ AsString();

			/// <returns>
			/// the address without display name as a string
			/// </returns>
			Platform::String^ AsStringUriOnly();

			/// <summary>
			/// Same as AsString.
			/// </summary>
			Platform::String^ ToString();

			LinphoneAddress(Platform::String^ address);

		private:
			Platform::String^ address;
		};
	}
}