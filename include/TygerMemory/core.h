// core.h

#pragma once
#ifdef TYGERMEM_EXPORTS
#define TYGERMEM __declspec(dllexport)
#else
#define TYGERMEM __declspec(dllimport)
#endif
#include <vector>
#include <string>
#include <functional>
#include "logging.h"
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>

class TYGERMEM Core
{
private:
	static DWORD processId;
	static HANDLE hProcess;
public:
	static uintptr_t moduleBase;
	/// <summary>
	///		Initializes the API by passing it the exe module handle for address offsets.
	/// </summary>
	/// <param name="hModule:">
	///		<para>The exe module handle.</para>
	///		<para>For usage with TygerFramework, use:</para>
	///		<c>Core::initialize((HMODULE)API::Get()->param()->TyHModule)</c>
	/// </param>
	/// <returns>
	///		<para>True if successfully initialized.</para>
	///		<para>This should be checked before using the API to avoid access violations.</para>
	/// </returns>
	static bool initialize(HMODULE hModule);
	/// <summary>
	///		Gets the address pointed to by a given path.
	/// </summary>
	/// <param name="baseAddress:">
	///		<para>The base address for the path.</para> 
	///		<para>This is assumed relative to the module base.</para>
	/// </param>
	/// <param name="offsets:">
	///		<para>A vector (list) of the integer offsets in the path.</para>
	/// </param>
	/// <returns>
	///		<para>The address pointed to by the path provided.</para>
	/// </returns>
	static uintptr_t getPointerAddress(uintptr_t baseAddress, const std::vector<int>& offsets);
};