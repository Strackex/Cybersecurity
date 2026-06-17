# Cybersecurity Learning Roadmap

## 1. Networking Fundamentals
### 1.1 OSI Model
- Understand all 7 layers
- Data flow and encapsulation

### 1.2 TCP/IP Model & Protocols
- TCP/IP architecture
- Ports and protocols (HTTP/HTTPS, FTP, SSH, etc.)
- Common port numbers

### 1.3 Core Networking Concepts
- DNS (Domain Name System)
- DHCP (Dynamic Host Configuration Protocol)
- IP addressing and subnetting

---

## 2. Kali Linux
### 2.1 Basic Commands
- File operations: `ls -la`, `cd`, `mkdir`
- Permissions: `chmod`, `chown`
- System: `sudo`, `apt-get`
- Networking: `ifconfig`, `ping`

### 2.2 Privilege Escalation
- Complete series on privilege escalation
- Linux privilege escalation techniques
- Windows privilege escalation

---

## 3. Web Applications
### 3.1 HTTP Protocol
- HTTP Request/Response cycle
- HTTP methods (GET, POST, etc.)
- HTTP status codes

### 3.2 State Management
- Cookies and sessions
- Session hijacking prevention
- Secure cookie attributes

### 3.3 Burp Suite
- Proxy configuration
- Repeater and Intruder
- Scanner and Extensions

---

## 4. Vulnerabilities

### 4.1 OWASP Top 10
- **Broken Access Control** - IDOR, privilege escalation
- **Cryptographic Failures** - Weak encryption, improper storage
- **Injection** - SQL, NoSQL, Command injection
- **Insecure Design** - Architecture flaws
- **Security Misconfiguration** - Default credentials, exposed ports
- **Vulnerable & Outdated Components** - Known vulnerabilities
- **Identification & Authentication Failures** - Session management issues
- **Software & Data Integrity Failures** - Supply chain attacks
- **Security Logging & Monitoring Failures** - Detection gaps
- **Server-Side Request Forgery (SSRF)** - Internal network access

### 4.2 Cross-Site Request Forgery (CSRF)
- Understanding CSRF attacks
- Prevention techniques

### 4.3 Practice Platforms
- **DVWA (Damn Vulnerable Web Application)**
  - All difficulty levels
  - All vulnerability modules
- **OWASP Juice Shop**
  - Modern JavaScript challenges
  - Real-world vulnerabilities

---

## 5. Methodology & Professionalism

### 5.1 Cyber Kill Chain
1. **Reconnaissance**
   - Footprinting
   - OSINT (Open Source Intelligence)
   - Social media investigation

2. **Weaponization**
   - Exploit development
   - Payload creation

3. **Delivery**
   - Phishing
   - Drive-by downloads

4. **Exploitation**
   - Metasploit framework
   - Custom exploits

5. **Installation**
   - Backdoors
   - Remote Access Trojans (RATs)

6. **Command & Control (C2)**
   - C2 infrastructure
   - Communication channels

7. **Actions on Objectives**
   - Data exfiltration
   - System compromise

### 5.2 Phases Implementation
- **Reconnaissance**: Use OSINT for information gathering
- **Scanning/Enumeration**: Nmap for mapping and discovery
- **Gaining Access**: Metasploit for exploits and payloads
- **Maintaining Persistence**: Backdoors and scheduled tasks
- **Covering Tracks**: Log evasion and cleanup

---

## 6. Mathematics & Cryptography

### 6.1 Cryptographic Fundamentals
- **Symmetric Encryption**
  - AES, DES, RC4
  - Key management

- **Asymmetric Encryption**
  - RSA, ECC
  - Digital signatures

- **Hashing**
  - MD5 (Message Digest 5)
  - SHA-256 (Secure Hash Algorithm)
  - Hash collisions and security

### 6.2 Password Attacks
- **Brute Force Attacks**
  - Dictionary attacks
  - Hybrid attacks

- **Tools**
  - **Hashcat** - GPU accelerated
  - **John the Ripper** - CPU based
  - **rockyou.txt** - Common password wordlist

---

## 7. System Security (Blue Team)

### 7.1 System Architectures
- **Windows Architecture**
  - Kernel and user modes
  - Registry and services
  
- **Linux Architecture**
  - Kernel and user space
  - Init systems

### 7.2 Authentication Systems
- Windows authentication
- Linux authentication (PAM)
- Multi-factor authentication (MFA)

### 7.3 Active Directory
- Domain Controllers
- Forest and Domain structure
- Group Policy Objects (GPO)

### 7.4 File System Security
- NTFS permissions
- Linux file permissions
- Access Control Lists (ACLs)

### 7.5 Principle of Least Privilege
- User rights minimization
- Service accounts
- Application permissions

### 7.6 Firewalls
- Ingress and egress rules
- Stateful vs Stateless
- Application-layer filtering

### 7.7 Endpoint Detection & Response (EDR)
- Behavioral detection
- Incident response
- Threat hunting

### 7.8 System Hardening
- Port management
- Service minimization
- Security updates
- MFA implementation

---

## 8. Network Security & Attacks

### 8.1 IDS/IPS (Intrusion Detection/Prevention)
- Signature vs Anomaly based
- Network vs Host-based
- Deployment strategies

### 8.2 VPN Technologies
- **Enterprise Protocols**
  - IPsec (Layer 2)
  - OpenVPN
  - WireGuard

### 8.3 ARP Attacks
- ARP Spoofing/Poisoning
- SSL/TLS certificate stripping
- MITM (Man-in-the-Middle)

### 8.4 DoS/DDoS Attacks
- Volumetric attacks
- **NTP Amplification**
- DNS amplification
- Application layer attacks

### 8.5 Slowloris Attack
- HTTP/HTTPS DoS
- Connection exhaustion
- Mitigation techniques

---

## 9. Essential Security Tools

### 9.1 The "Big Four"
1. **Nmap** - Network mapping and scanning
2. **Wireshark** - Packet analysis and monitoring
3. **Metasploit** - Exploitation framework
4. **Burp Suite** - Web application testing

### 9.2 Additional Tools
- **Nikto** - Web server scanning
- **Hydra** - Password brute-forcing
- Other tools as needed

---

## 10. Practical Application & CTFs

### 10.1 Capture The Flag (CTF)
- **Cron jobs** - Automated task vulnerabilities
- **Weak file permissions** - Privilege escalation
- **Enumeration scripts** - `linpeas.sh`, `winpeas.exe`
- Various CTF platforms

### 10.2 Practice Scenarios
- Real-world simulations
- Vulnerable machines (HackTheBox, TryHackMe)
- Penetration testing challenges

---

## 11. Report Writing

### 11.1 Penetration Testing Reports
- Executive summary
- Methodology
- Findings and vulnerabilities
- Exploitation details
- Recommendations
- Proof of concept (PoC)

### 11.2 Documentation Skills
- Clear technical writing
- Risk assessment
- Remediation strategies
- Professional presentation

---

## Learning Path Progression

### Phase 1: Foundation (1-2 months)
- Networking Fundamentals (Sections 1-2)
- Linux basics (Section 2.1)
- HTTP and web basics (Section 3.1-3.2)

### Phase 2: Intermediate (2-3 months)
- Kali Linux & Privilege Escalation (Section 2.2)
- OWASP Top 10 (Section 4.1)
- Practice with DVWA (Section 4.2)

### Phase 3: Advanced (3-4 months)
- All tools (Section 9)
- System security (Section 7-8)
- CTF challenges (Section 10)

### Phase 4: Professional (2-3 months)
- Methodologies (Section 5)
- Report writing (Section 11)
- Enterprise scenarios

### Phase 5: Specialization (Ongoing)
- Advanced cryptography
- Specific tools and techniques
- Real-world experience

---

*"The only way to truly understand security is to understand both offense and defense."*
