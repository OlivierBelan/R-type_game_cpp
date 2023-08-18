/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Client
*/

#pragma once

#include <iostream>

namespace RType {
	class AClient {
	public:
		AClient() = default;
		~AClient() = default;

	public:
		virtual std::string getIpv4() const noexcept = 0;
		virtual unsigned short getPort() const noexcept = 0;
		virtual void send(const uint8_t *buffer, const std::size_t &len) noexcept = 0;

	public:
		void setId(unsigned int new_id) noexcept;
		unsigned int getId() const noexcept;
		void setUDP(unsigned int new_udp) noexcept;
		unsigned int getUDP() const noexcept;

	private:
		unsigned int _id = 0;
		unsigned int _udp = 0;
	};
}; // namespace RType
