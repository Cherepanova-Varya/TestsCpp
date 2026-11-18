#pragma once
#include <exception>
#include <string>

class FleetError : public std::exception {
private:
	std::string Message;
public:
	FleetError(std::string mes): Message(mes) {}
	const char* what() const noexcept override { return Message.c_str(); }
};

class RejectError: public FleetError {
public:
	RejectError(std::string mes): FleetError(mes) {}
};

class ArgumentError : public FleetError {
public:
	ArgumentError(std::string mes): FleetError(mes) {}
};

class NotFoundError : public FleetError {
public:
	NotFoundError(std::string mes): FleetError(mes) {}
};