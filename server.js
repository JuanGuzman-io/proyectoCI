require('dotenv').config();
const express = require('express');
const app = express();
const cors = require('cors');

//middleware
app.use(cors());
app.use(express.json());

//routes
app.use('/datos', require('./routes/datos'));

const port = process.env.PORT || 3001;

app.listen(port, () => {
    console.log(`Server is up on port ${port}`);
});