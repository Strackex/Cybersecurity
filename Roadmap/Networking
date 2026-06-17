# **Networking** 

## 1. The OSI Model

* **Application Layer** - Interface (All Protocols, like HTTPS)
* **Presentation Layer** - Conversion (Machine Language), Encryption and Compression
* **Session Layer** - Dialogue Control and Token Management (Server giving specific token if its free)
* **Transport Layer** - Segmentation of Data into Data units (Sequence Number and Source Destination Number), also helps in Flow and Error Control
* **Network Layer** - Data Segments -> Assigns IP of sender and receiver -> Forms Packet for correct destination and Path Determination
* **Datalink layer** - Physical Addressing The IP packets -> Assigns Mac Address -> Frame
* **Physical layer** -> Frames (bits), Two devices might be connected via Ethernet cable - Electric Signal, Fibre Optic - Light Signal, Wireless - waves
## 2. The TCP/IP model and concepts of ports and protocols

### Layer 4: Application Layer
* It handles direct interface with software, data formatting, encryption, and session initialization.
* **Key Protocols:**
    * `HTTP / HTTPS` (Web traffic - Port 80 / 443)
    * `DNS` (Domain resolution - Port 53)
    * `SSH` (Secure remote access - Port 22)
    * `FTP / SFTP` (File transfers - Port 21 / 22)

### Layer 3: Transport Layer
* Manages host-to-host data delivery, error checking, flow control, and data segmentation.
* **TCP (Transmission Control Protocol):** Connection-oriented. Reliable, tracks sequence numbers, guarantees data delivery in order, retransmits lost data.
* **UDP (User Datagram Protocol):** Connectionless. Fire-and-forget, zero tracking, lightweight, extremely fast. Used for streaming, gaming, and rapid queries (like DNS).

### Layer 2: Internet Layer
* It is responsible for logical addressing (IPs) and global routing. It determines the best paths for data packets to traverse physical networks.
* **Key Protocols:**
    * `IP` (IPv4 / IPv6 addressing)
    * `ICMP` (Diagnostic messages — used by the `ping` utility)
    * `ARP` (Address Resolution Protocol — translates an internal IP to a hardware MAC address)

### Layer 1: Network Access Layer
* It interfaces directly with network hardware, turning data packets into frames and electric/light/radio waves over a physical medium.
* Ethernet, `Wi-Fi (802.11)` protocols, hardware Network Interface Cards (NICs), and Layer 2 network switches.
### The TCP 3-Way Handshake

Before a client and a server can send any actual web data over TCP, they must perform an explicit synchronization ritual to open a connection channel.

1.  **`SYN` (Synchronize):** The client sends a packet containing a random initial sequence number ($ISN_c$) with the `SYN` flag turned on.
    * *Translation:* "Hey server, I want to talk to you. Let's sync up using this starting sequence number."
2.  **`SYN-ACK` (Synchronize-Acknowledge):** The server receives it, increments the client's number by 1, and sends back a packet with both the `SYN` and `ACK` flags turned on. It generates its own initial sequence number ($ISN_s$).
    * *Translation:* "I hear you, client! I acknowledge your number. Here is my sequence number, let's sync on my side too."
3.  **`ACK` (Acknowledge):** The client receives the packet, increments the server's sequence number by 1, and sends a final packet with just the `ACK` flag turned on.
    * *Translation:* "Got it. Connection is open. Let's start trading real data."

When using network mapping tools like `nmap`, a default scan (called a SYN Stealth Scan / Half-Open Scan) starts a 3-way handshake by sending a `SYN` packet.

* If the server responds with a `SYN-ACK`, `nmap` knows the port is **open**.
* Instead of sending the final `ACK` to complete the connection, `nmap` immediately sends a `RST` (Reset) packet to tear down the connection. This prevents the target server application from logging a fully established connection attempt, helping you map the network quietly.
### Data Encapsulation

As data travels down the TCP/IP stack from your application to the wire, each layer wraps the data with its own header information:

1.  **Application Layer:** Raw Web Data (`GET /index.php`)
2.  **Transport Layer:** Adds TCP Header (Source Port, Destination Port) -> Segment
3.  **Internet Layer:** Adds IP Header (Source IP, Destination IP) -> Packet
4.  **Network Access Layer:** Adds MAC Address Header -> Frame
5.  **The Wire:** Bits transmitted over copper/fiber/waves (`10101100`)
