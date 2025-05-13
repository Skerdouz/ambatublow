class Bank {
public:
	Bank() : balance(0) {}
	int getBalance() const;
	void setBalance(const int amount);
	void addBalance(const int amount);
	void subtractBalance(const int amount);
private:
	int balance;
};