const router = require('express').Router();
const db = require('../db');

router.get('/', async (req, res) => {
    try {
        const result = await db.query(
            'SELECT * from datos'
        );
        res.status(200).json(
            {
                status: 'Success',
                result: result.rows.length,
                datoNodo: result.rows
            }
        );
    } catch (error) {
        console.log(error);
    }
});

router.post('/post', async (req, res) => {
    // console.log(req.bodyx|);
    try {
        const result = await db.query(
            'INSERT INTO datos (idNodo, nivelSonoro, alerta) VALUES ($1, $2, $3) returning *',
            [req.body.idNodo, req.body.nivelSonoro, req.body.alerta]
        );
        res.status(201).json(
            {
                status: 'Success',
                datos: result.rows[0]
            }
        );
    } catch (error) {
        console.log(error);
    }
});

router.post('/alerta', async (req, res) => {
    console.log(req.body);
    try {
        const result = await db.query(
            'INSERT INTO atencion (direccion, nombre, alarma) VALUES ($1, $2, $3) returning *',
            [req.body.direccion, req.body.nombre, req.body.alarma]
        );
        res.status(201).json(
            {
                status: 'Success',
                datos: result.rows[0]
            }
        );
        console.log(result);
    } catch (error) {
        console.log(error);
    }

});

module.exports = router;