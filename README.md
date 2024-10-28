# SNHU-Projects

1. Briefly summarize your client, Artemis Financial, and its software requirements. Who was the client? What issue did the company want you to address?

Artemis Financial, a consulting firm that provides personalized financial plans, needed to enhance its web application security to protect client data. They specifically required file verification through a checksum to ensure data integrity and secure data transfer mechanisms. My role involved analyzing the existing application for vulnerabilities and implementing encryption to meet their requirements for safe and secure client communications.

2. What did you do well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall well-being?

I systematically identified and resolved vulnerabilities, updating insecure libraries, implementing AES-256 encryption, and using SHA-256 for data integrity. Secure coding is essential to prevent data breaches and safeguard sensitive information. For a company, strong software security protects client trust, minimizes compliance risks, and enhances its reputation in the market, creating a secure foundation for growth.

3. Which part of the vulnerability assessment was challenging or helpful to you?

The most challenging yet insightful part was managing third-party dependencies using OWASP Dependency Check. It required careful handling to ensure no vulnerabilities were introduced through indirect or transitive dependencies. This aspect highlighted the importance of dependency management in software security and enhanced my approach to preventing vulnerabilities in future projects.

4. How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?

I strengthened security by implementing AES-256 encryption, SHA-256 for checksum verification, and HTTPS for secure communication. These layers provided comprehensive data protection. In future projects, I’d use tools like OWASP Dependency Check and SonarQube to assess vulnerabilities and would prioritize mitigations based on their severity and potential impact on data confidentiality and integrity.

5. How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities?

I tested functionality by running the application over HTTPS and verifying checksum operations. Then, I performed static analysis and dependency checks to ensure no additional vulnerabilities were introduced during refactoring. Post-testing, I confirmed that all security features worked as intended and that the application remained secure and stable after updates.

6. What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?

I used OWASP Dependency Check, Java Keytool for certificate generation, AES-256 encryption for data protection, SHA-256 hashing for data integrity, and enforced HTTPS. These tools and practices are valuable in any project requiring secure communication, dependency management, and compliance with software security standards, ensuring a strong approach to software security.

7. Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?

From this assignment, I’d highlight my skills in identifying and addressing software security vulnerabilities, including encryption (AES-256), secure communication (HTTPS), and dependency management. I would present my Practices for Secure Software Report, along with screenshots and testing evidence, as proof of my commitment to secure coding standards and practical application of secure software development principles.
