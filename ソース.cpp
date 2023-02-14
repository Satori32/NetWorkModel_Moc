#include <iostream>
#include <vector>
#include <cstdint>

//this is moc. not work on standalone.
//and this is moc of skin. we need implement by realism.

typedef void* Handle;//this is like a undefined.
typedef void* Address;//this is like a undefined.
typedef void* ID;//this is like a undefined.

const char Sig[] = "VirtalLTEHeader\n\0";
const char Version[] = "0.01a\n\0";
struct LTE {
	char Sig[32]{};
	char Varsion[16]{};
	Address To{};
	Address From{};
	ID UniqueID{};
	std::size_t MesssageID{};
	std::uint8_t Reserved[128];
	std::size_t DataSize{};
	std::uint8_t* Data;
};

static const int XXXXXX__ = sizeof(LTE);

Handle LTEOpen() { return (void*)0xdeadbeef; }
bool LTEClose(Handle In) { return true; }

bool LTEConnect(Handle In) { return true; }
bool LTEDisConnect(Handle In) { return true; }
bool LTEIsConnecting(Handle In) { return false; }

bool LTESendReTry(Handle In, std::size_t MessageID) { return true; }
bool LTEReQuestReTry(Handle In, std::size_t MessageID) { return true; }

bool LTEWrite(Handle In, std::uint8_t* Bytes, std::size_t L) {

	//do something.
	//Send to lte network.

	return true;
}

std::vector<std::uint8_t> LTERead(Handle In,std::size_t L) {

	//do something.
	//get from let network.


	return {};
}

class NetworkIO {
public:
	NetworkIO() { Open(); }
	virtual ~NetworkIO() { DisConnect(); Close(); }

	bool Open() { return false; }
	bool Close() { return true; }
	bool Connect(std::uint8_t A, std::uint8_t B, std::uint8_t C, std::uint8_t D,std::uint16_t Port) { return false; }
	bool DisConnect() { return false; }
	bool IsConnecting() { return  true; }

	bool Write(const std::uint8_t* P, std::size_t L) { return true; }
	std::vector<std::uint8_t> Read(std::size_t L) { return {}; }
protected:
	Handle H = nullptr;
	const char Sig[32] = "NetworkHeader\n\0";
	//std::vector<std::uint8_t> D;
};

int main() {
	NetworkIO Net;
	std::uint8_t S[] = "HellowWorld!";
	Net.Connect(192, 168, 1, 128, 80);
	if (!Net.IsConnecting()) { return -1; }
	Net.Write(S, sizeof(S));
	auto D = Net.Read(128);

	Net.DisConnect();

	return 0;

}