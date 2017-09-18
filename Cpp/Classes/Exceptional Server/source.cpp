		/* Enter your code here. */
        int computed;
        try {
            computed = Server::compute(A, B);
            cout << computed << endl;
        } catch (bad_alloc& e) {
            cout << "Not enough memory" << endl;
        } catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        } catch (...) {
            cout << "Other Exception" << endl;
        }