#include "MeigaException.h"
#include <sstream>


MeigaException::MeigaException(int line, const char* file) 
	:
	line(line)
, file(file)
{}

const char* MeigaException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* MeigaException::GetType() const noexcept
{
	return "Meiga Exception";
}

int MeigaException::GetLine() const noexcept
{
	return line;
}

const std::string& MeigaException::GetFile() const noexcept
{
	return file;
}

std::string MeigaException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}